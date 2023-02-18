/* File generated by agar bundlecss */
const char *agStyleDefault_Data = 
	"/*\n"
	" * Default Agar Stylesheet.\n"
	" * ex:syn=agarcss\n"
	" *\n"
	" * Colors and font attributes of parents are inherited by default (unless\n"
	" * overridden by an instance Variable or matching stylesheet definition).\n"
	" * Padding and spacing attributes are not inherited by default.\n"
	" *\n"
	" * See: AG_StyleSheet(3) and \"STYLE ATTRIBUTES\" section of AG_Widget(3).\n"
	" */\n"
	"AG_Box {\n"
	"padding: 2 3 2 3;                          /* top right bottom left */\n"
	"spacing: 3 2;                              /* horiz vert */\n"
	"}\n"
	"AG_Button {\n"
	"padding: 5 10 5 10;\n"
	"color#focused: #808081;\n"
	"color#hover: #818180;\n"
	"selection-color#focused: #646496;\n"
	"selection-color#hover: #969664;\n"
	"}\n"
	"AG_Checkbox {\n"
	"spacing: 5;\n"
	"background-color#hover: rgb(80,80,120);\n"
	"}\n"
	"/*\n"
	" * AG_Combo > #trigger {\n"
	" * 	padding: 1;\n"
	" * }\n"
	" * AG_Combo > #list {\n"
	" * 	background-color: #474747;\n"
	" * }\n"
	" */\n"
	"AG_Console {\n"
	"font-family: monoalgue;\n"
	"padding: 4;\n"
	"spacing: 4;\n"
	"background-color: rgb(0,0,0);\n"
	"background-color#hover: rgb(0,0,30);\n"
	"background-color#focused: rgb(5,5,5);\n"
	"background-color#disabled: rgb(10,10,10);\n"
	"text-color: rgb(240,240,240);\n"
	"}\n"
	"AG_Editable {\n"
	"padding: 1;\n"
	"background-color: #0000;\n"
	"}\n"
	"AG_FileDlg {\n"
	"spacing: 2;\n"
	"padding: 3;\n"
	"}\n"
	"AG_Icon {\n"
	"spacing: 4 0;\n"
	"}\n"
	"AG_Label {\n"
	"padding: 2 6 2 6;\n"
	"background-color: #0000;\n"
	"background-color#focused: #0000;\n"
	"}\n"
	"AG_Menu {\n"
	"padding: 2 5 2 5;\n"
	"color: rgb(60,60,60);\n"
	"color#disabled: rgb(40,40,110);\n"
	"selection-color: rgb(40,40,110);\n"
	"text-color#disabled: rgb(170,170,170);\n"
	"}\n"
	"AG_MenuView {\n"
	"padding: 4 8 4 8;\n"
	"spacing: 8 0;\n"
	"color: rgb(60,60,60);\n"
	"selection-color: rgb(40,40,110);\n"
	"color#disabled: rgb(40,40,110);\n"
	"text-color#disabled: rgb(170,170,170);\n"
	"}\n"
	"AG_Pane {\n"
	"line-color#hover: rgb(200,200,180);\n"
	"}\n"
	"AG_ProgressBar {\n"
	"font-family: league-gothic;\n"
	"font-size: 90%;\n"
	"padding: 2;\n"
	"}\n"
	"AG_Radio {\n"
	"spacing: 1;\n"
	"background-color#hover: rgb(80,80,120);\n"
	"}\n"
	"AG_Textbox {\n"
	"spacing: 5;\n"
	"}\n"
	"AG_Titlebar {\n"
	"font-size: 90%;\n"
	"padding: 3;\n"
	"spacing: 1;\n"
	"color: rgb(40,50,60);\n"
	"color#disabled: rgb(35,35,35);\n"
	"}\n"
	"AG_Toolbar {\n"
	"padding: 0;\n"
	"spacing: 1;\n"
	"}\n"
	"AG_Scrollbar {\n"
	"line-color#hover: rgb(200,200,180);\n"
	"}\n"
	"AG_Separator {\n"
	"line-color: #888;\n"
	"padding: 8 10 8 10;\n"
	"}\n"
	"AG_Statusbar {\n"
	"font-family: charter;\n"
	"padding: 2;\n"
	"spacing: 1;\n"
	"}\n"
	"AG_Tlist {\n"
	"padding: 1 0 2 0;\n"
	"spacing: 4 0;\n"
	"}\n"
	"AG_Window {\n"
	"padding: 0 3 4 3;\n"
	"background-color: #575757;\n"
	"}\n"
	"";

AG_StaticCSS agStyleDefault = {
	"agStyleDefault",
	2228,
	&agStyleDefault_Data,
	NULL
};
