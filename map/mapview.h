/*	Public domain	*/

#ifndef _AGAR_MAP_MAPVIEW_H_
#define _AGAR_MAP_MAPVIEW_H_

#include <agar/gui/widget.h>
#include <agar/gui/menu.h>

#include <agar/map/begin.h>

struct map_view;
struct ag_toolbar;
struct ag_label;
struct ag_tlist;
struct ag_scrollbar;

enum map_view_mode {
	MAP_VIEW_EDITION,	/* Read/write edition */
	MAP_VIEW_EDIT_ATTRS,	/* Editing node attributes */
	MAP_VIEW_EDIT_ORIGIN,	/* Moving origin node */
	MAP_VIEW_PLAY,		/* Playing */
	MAP_VIEW_MODE_LAST
};

typedef struct map_view_draw_cb {
	void (*_Nonnull func)(struct map_view *_Nonnull, void *_Nullable);
	void *_Nullable p;
	AG_SLIST_ENTRY(map_view_draw_cb) draw_cbs;
} MAP_ViewDrawCb;

typedef struct map_view {
	AG_Widget wid;			/* AG_Widget -> MAP_View */

	Uint flags;
#define MAP_VIEW_EDIT          0x001	/* Mouse/keyboard edition */
#define MAP_VIEW_GRID          0x002	/* Display the grid */
#define MAP_VIEW_CENTER        0x004	/* Request initial centering */
#define MAP_VIEW_NO_CURSOR     0x008	/* Disable the cursor */
#define MAP_VIEW_NO_BMPSCALE   0x010	/* Disable bitmap scaling */
#define MAP_VIEW_NO_BG         0x020	/* Disable background tiles */ 
#define MAP_VIEW_NO_NODESEL    0x040	/* Disable node selections */
#define MAP_VIEW_SET_ATTRS     0x080	/* Setting node attributes */
#define MAP_VIEW_SHOW_ORIGIN   0x200	/* Show map origin node */
#define MAP_VIEW_NO_SCROLLBARS 0x400	/* Disable scrollbars */

	enum map_view_mode mode;	/* Edition mode */
	Uint edit_attr;			/* Attribute being edited (EDIT_ATTRS) */
	int attr_x, attr_y;		/* Node of last attribute toggle (EDIT_ATTRS */

	int wPre, hPre;			/* Prescaling (nodes) */

	AG_Color color;
	struct {			/* Mouse scrolling state */
		int scrolling;		/* Scrolling is in progress */
		int x, y;		/* Current node coordinates */
		int xmap, ymap;		/* Current map coordinates */
		int xmap_rel, ymap_rel;	/* Relative map coordinates */
	} mouse;
	struct {			/* Temporary mouse selection */
		int set;		/* Selection is set */
		int x, y;		/* Origin of rectangle */
		int xOffs, yOffs;	/* Displacement from origin */
	} msel;
#if AG_MODEL == AG_LARGE
	Uint32 _pad1;
#endif
	struct {
		int set;		/* Effective selection is defined */
		Uint flags;
#define MAP_VIEW_SELECTION_MOVING 0x01	/* Selection is being moved */
#define MAP_VIEW_SELECTION_MOVED  0x02	/* Selection has been moved */
		MAP map;		/* Temporary copy of the nodes */
		int x, y;		/* Origin of the rectangle */
		int w, h;		/* Dimensions of the rectangle */
		int xOrig, yOrig;	/* Original position (if MOVING) */
	} esel;

	MAP *_Nullable map;		/* Agar MAP(3) to display */

	int cam;			/* Name of map camera to use */
	int mx, my;			/* Display offset (nodes) */
	int xOffs, yOffs;		/* Display offset (pixels) */
	Uint mw, mh;			/* Display size (nodes) */
	Uint wVis, hVis;		/* Visible area (pixels) */
	AG_Rect r;			/* View area */

	int cx, cy;			/* Cursor position (nodes) */
	int cxoffs, cyoffs;		/* Cursor offset (pixels) */
	int cxrel, cyrel;		/* Relative displacement (nodes) */
	int dblclicked;			/* Double click flag */

	struct ag_toolbar *_Nullable toolbar;		/* Edit tools */
	struct ag_statusbar *_Nullable statusbar;	/* Status display */
	struct ag_label *_Nonnull status;		/* Status label */
	struct ag_tlist *_Nonnull lib_tl;		/* Libraries */
	struct ag_tlist *_Nonnull objs_tl;		/* Objects */
	struct ag_tlist *_Nonnull layers_tl;		/* Layers */
	struct ag_scrollbar *_Nullable hbar;		/* Horizontal scrollbar */
	struct ag_scrollbar *_Nullable vbar;		/* Vertical scrollbar */
	AG_PopupMenu *_Nullable popup;			/* Right-click menu */

	MAP_Tool *_Nullable curtool;			/* Selected tool */
	MAP_Tool *_Nullable deftool;			/* Default tool if any */

	AG_TAILQ_HEAD_(map_tool) tools;			/* Map edition tools */
	AG_SLIST_HEAD_(map_view_draw_cb) draw_cbs;	/* Post-draw callbacks */
} MAP_View;

#define MAPVIEW(obj)            ((MAP_View *)(obj))
#define MAPCVIEW(obj)           ((const MAP_View *)(obj))
#define MAP_VIEW_SELF()          MAPVIEW( AG_OBJECT(0,"AG_Widget:MAP_View:*") )
#define MAP_VIEW_PTR(n)          MAPVIEW( AG_OBJECT((n),"AG_Widget:MAP_View:*") )
#define MAP_VIEW_NAMED(n)        MAPVIEW( AG_OBJECT_NAMED((n),"AG_Widget:MAP_View:*") )
#define MAP_CONST_VIEW_SELF()   MAPCVIEW( AG_CONST_OBJECT(0,"AG_Widget:MAP_View:*") )
#define MAP_CONST_VIEW_PTR(n)   MAPCVIEW( AG_CONST_OBJECT((n),"AG_Widget:MAP_View:*") )
#define MAP_CONST_VIEW_NAMED(n) MAPCVIEW( AG_CONST_OBJECT_NAMED((n),"AG_Widget:MAP_View:*") )

#define MAP_CAM(mv)	(mv)->map->cameras[(mv)->cam]
#define MAP_ZOOM(mv)	MAP_CAM(mv).zoom
#define MAP_TILESZ(mv)	MAP_CAM(mv).tilesz
#define MAP_PIXELSZ(mv)	MAP_CAM(mv).pixsz

__BEGIN_DECLS
extern AG_WidgetClass mapViewClass;

MAP_View *_Nonnull MAP_ViewNew(void *_Nullable, MAP *_Nullable, Uint,
                               struct ag_toolbar *_Nullable,
                               struct ag_statusbar *_Nullable);

void MAP_ViewSizeHint(MAP_View *_Nonnull, int,int);
void MAP_ViewCenter(MAP_View *_Nonnull, int,int);
void MAP_ViewSetScale(MAP_View *_Nonnull, Uint, int);

void MAP_ViewSetSelection(MAP_View *_Nonnull, int,int, int,int);
int  MAP_ViewGetSelection(MAP_View *_Nonnull,
                          int *_Nonnull, int *_Nonnull,
                          int *_Nonnull, int *_Nonnull);

void MAP_ViewRegDrawCb(MAP_View *_Nonnull,
                       void (*_Nullable)(MAP_View *_Nonnull, void *_Nullable),
                       void *_Nullable);

void MAP_ViewUpdateCamera(MAP_View *_Nonnull);

void MAP_ViewStatus(MAP_View *_Nonnull, const char *_Nonnull, ...);
void MAP_ViewSetMode(MAP_View *_Nonnull, enum map_view_mode);

MAP_Tool *_Nonnull  MAP_ViewRegTool(MAP_View *_Nonnull,
                                    const MAP_ToolOps *_Nonnull, void *_Nullable);
MAP_Tool *_Nullable MAP_ViewFindTool(MAP_View *_Nonnull, const char *_Nonnull);

void MAP_ViewSetDefaultTool(MAP_View *_Nonnull, MAP_Tool *_Nonnull);
void MAP_ViewSelectTool(MAP_View *_Nonnull, MAP_Tool *_Nullable,
                        void *_Nullable);

static __inline__ void
MAP_ViewPixel2i(MAP_View *_Nonnull mv, int x, int y)
{
	if (mv->color.a < AG_OPAQUE) {
		AG_BlendPixel(mv, x,y, &mv->color, AG_ALPHA_SRC);
	} else {
		AG_PutPixel(mv, x,y, &mv->color);
	}
}
static __inline__ void
MAP_ViewHLine(MAP_View *_Nonnull mv, int x1, int x2, int y)
{
	AG_DrawLineH(mv, x1, x2, y, &mv->color);
}
static __inline__ void
MAP_ViewVLine(MAP_View *_Nonnull mv, int x, int y1, int y2)
{
	AG_DrawLineV(mv, x, y1, y2, &mv->color);
}
__END_DECLS

#include <agar/map/close.h>
#endif /* _AGAR_MAP_MAPVIEW_H_ */
