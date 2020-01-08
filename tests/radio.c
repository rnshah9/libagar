/*	Public domain	*/

#include "agartest.h"

typedef struct {
	AG_TestInstance _inherit;
	Uint myValue;
} MyTestInstance;

static int
TestGUI(void *obj, AG_Window *win)
{
	const char *items[] = {
		"Homer Simpson",
		"Marge Simpson",
		"Bart Simpson",
		"Lisa Simpson",
		"Maggie Simpson",
		"Santa's Little Helper",
		"Snowball II/V",
		"Abraham Simpson",
		"Abu Nahasapeemapetilon",
		"Barney Gumble",
		"Chief Clancy Wiggum",
		"Dewey Largo",
		"Eddie",
		"Edna Krabappel",
		"Itchy",
		"Janey Powell",
		"Jasper Beardsley",
		"Kent Brockman",
		"Krusty The Clown",
		"Lenny Leonard",
		"Lou",
		"Martin Prince",
		"Milhouse Van Houten",
		"Moe Szyslak",
		"Mr. Burns",
		"Ned Flanders",
		"Otto Mann",
		"Patty Bouvier",
		"Ralph Wiggum",
		NULL
	};
	AG_Box *box;
	AG_Label *lbl;
	MyTestInstance *ti = obj;

	box = AG_BoxNewVert(win, AG_BOX_EXPAND);

	AG_LabelNewS(box, AG_LABEL_FRAME, "Hello!");
	AG_LabelNewS(box, AG_LABEL_FRAME, "Two\nLines");
	
	lbl = AG_LabelNewS(box, AG_LABEL_HFILL | AG_LABEL_FRAME,
	    "Radio Group Test\n"
	    "Value: 1234");
	AG_LabelJustify(lbl, AG_TEXT_CENTER);
	AG_LabelValign(lbl, AG_TEXT_TOP);
	AG_SetStyle(lbl, "font-size", "150%");

	lbl = AG_LabelNewPolled(box, AG_LABEL_EXPAND | AG_LABEL_FRAME,
	    "Radio Group Test\n"
	    "Value: %i", &ti->myValue);

	AG_LabelJustify(lbl, AG_TEXT_CENTER);
	AG_LabelValign(lbl, AG_TEXT_TOP);
	AG_SetStyle(lbl, "font-size", "150%");

	AG_RadioNewUint(box, 0, items, &ti->myValue);
	return (0);
}

static int
Init(void *obj)
{
	MyTestInstance *ti = obj;

	ti->myValue = 1;
	return (0);
}

const AG_TestCase radioTest = {
	"radio",
	N_("Test AG_Radio(3) group"),
	"1.6.0",
	0,
	sizeof(MyTestInstance),
	Init,
	NULL,		/* destroy */
	NULL,		/* test */
	TestGUI,
	NULL		/* bench */
};
