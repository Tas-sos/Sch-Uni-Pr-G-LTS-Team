#include <iostream>
#include <cstdlib> /* Είναι της C ;) */
#include <fstream> /* Για τα αρχεία. */
#include <sstream> /* Για το stringstream */
#include <vector>
#include "g_lts_team_lib.cpp"

using namespace std;


int main (void)

{

string file_name, line_buffer;

cout << "Δώσε το όνομα του αρχείου : "; cin >> file_name;

ifstream fp; /* Ρεύμα εισόδου ( I(N)fstream ) */

fp.open(file_name); /* Άνοιγμα του αρχείου για ανάγνωση. */

/* ===================== Έλεγχος ανοίγματος αρχείου ===================== */
if ( !fp )
	{
	cout << "Σφάλμα : Το αρχείο δεν μπόρεσε να ανοίξει." << endl;
	return -1;
	}
/* ===================== -------------------------- ===================== */
	
	
	
vector < int > ela[10]; /* Δημιουργία vector που περιέχει vectors ακεραίων. */

int i = -1;
while ( getline(fp, line_buffer)  ) /* Διαβάζω γραμμή γραμμή και το περιεχόμενο της γραμμής το πετάω σε ένα buffer. */
	{
	
	i++;
	ela[i] = split(line_buffer) ;  /* Κόβω το string ( line_buffer ) */
	
	}
	
		
print_vec_arry(ela, 10);

	


fp.close(); /* Κλείσιμο αρχείου. */


return 0;
}
