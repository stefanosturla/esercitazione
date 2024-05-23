#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "CQuadrilateral.h"

/// @brief default constructor 
Quadrilateral::Quadrilateral() {

	cout << "Quadrilateral - constructor - default" << endl;
	Init();

} 

/// @brief constructor ta a struct of type TextArea with infos on text and font size
Quadrilateral::Quadrilateral(TextArea ta) {
	
	cout << "Quadrilateral TextArea - constructor" << endl;
	 
	Init();

} 

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Quadrilateral::Quadrilateral(const Quadrilateral &o) {
	
	cout << "Quadrilateral - copy constructor" << endl;

	Init(o);
}

/// @brief destructor memory deallocation of an array dinamically created by new operator
Quadrilateral::~Quadrilateral() {

	cout << "Quadrilateral - destructor" << endl;
	Reset();
	delete tarea;
}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
void Quadrilateral::SetSides(float s1, float s2, float s3, float s4) {
	
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
	sides[3] = s4; 
	
	return;

} 

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Quadrilateral& Quadrilateral::operator=(const Quadrilateral &o) { 
	
	Init(o);

	return *this;
	
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Quadrilateral::operator==(const Quadrilateral &o) {

	return false;
}


/// @brief default initialization of the object and memory allocation 
void Quadrilateral::Init() {
	
	tarea = new(TextArea);
	tarea->size = 0;
	strcpy(tarea->string, "standard");
	SetSides(0.,0.,0.,0.);
	
	
}


/// @brief initialization of the object as a copy of an object, added the copy of string and size  
/// @param r reference to the object that should be copied 
void Quadrilateral::Init(const Quadrilateral &o) {
	Reset();
	Init();
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
	sides[3] = o.sides[3];
	strcpy(tarea->string, o.tarea->string);
	tarea->size = o.tarea->size;
	
}

/// @brief total reset of the object  
void Quadrilateral::Reset() {
	
	if (tarea != NULL) {
		delete tarea;
		tarea = NULL;
	}
	sides[0]= sides[1]= sides[2]= sides[3] = 0.;
	
}

/// @brief get the area of the object
/// @return area 
float Quadrilateral::GetArea() {
	
	return Area();

}

/// @brief get the perimeter of the object
/// @return perimeter 
float Quadrilateral::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]+sides[3]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
void Quadrilateral::GetSides(float &s0, float &s1, float &s2, float &s3) {

	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
	s3 = sides[3];

}

/// @brief get the info about the text area , size and string 
/// @param ta a struct of type TextArea to be filled
void Quadrilateral::GetTextArea(TextArea &ta) {

	ta.size = tarea->size;
	strcpy(ta.string, tarea->string);
} 

/// @brief get the text of the text area , string 
/// @param text the string used in the text area 
void Quadrilateral::GetText(char* text) {

	strcpy(text, tarea->string);
	
}

/// @brief get the font size of the text area 
/// @return the font size
unsigned int Quadrilateral::GetFontSize() {
	
	return tarea->size;
}


/// @brief set the text area of the object 
/// @param ta a struct of type TextArea filled with a text and a font size
void Quadrilateral::SetTextArea(TextArea ta) {

	tarea->size = ta.size;
	strcpy(tarea->string, ta.string);
}

/// @brief set the text of the text area 
/// @param text the text 
void Quadrilateral::SetText(char* text) {

	strcpy(tarea->string, text);

}

/// @brief set the font size of the text area 
/// @param size the font size 
void Quadrilateral::SetFontSize(unsigned int size) {

	tarea->size = size;
}



/// @brief write an error message 
/// @param string message to be printed
void Quadrilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Quadrilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Quadrilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Quadrilateral --";
	cout << string << endl;

}


/// @brief for debugging: all about the object , added output of size and string 
void Quadrilateral::Dump() {
	
	cout << endl;
	cout << "---Quadrilateral---" << endl; 
	cout << endl;
	
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << sides[3] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "FontSize = " << GetFontSize() << endl;
	cout << "FontType = " << tarea->string << endl;
	cout << "------------------" << endl; 
	cout << endl;

}

