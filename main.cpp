#include <iostream>
#include <cstdlib> /* Είναι της C ;) */
#include <fstream> /* Για τα αρχεία. */
#include <sstream> /* Για το stringstream */
#include <vector>
#include "g_lts_team_lib.cpp"

using namespace std;




int main (void)

{

string crs_file_name, stu_file_name, line_buffer;
vector <int> temp[1]; /* Προσωρινό vector με ένα (0) στοιχείο. */


crs_file_name = "car-s-91.crs" ;
//cout << "Δώσε το όνομα του αρχείου (.crs): "; cin >> crs_file_name;

stu_file_name = "car-s-91.stu";
//cout << "Δώσε το όνομα του αρχείου (.stu): "; cin >> stu_file_name;

/* Βρίσκω των αριθμό γραμμών κάθε αρχείου - που δείχνει αντίστοιχα : */
int mathimata = find_lines(crs_file_name)+1; /* Ο αριθμός των μαθημάτων +1 διότι δε θα παίζω με την πρώτη (0) θέση του πίνακα. */
int spoudastes = find_lines(stu_file_name)+1; /* Ο αριθμός των σπουδαστών +1 διότι δε θα παίζω με την πρώτη (0) θέση του πίνακα. */


/* Οπότε κάνω κατευθείαν τις δομές (vectors & arrays επέλεξα τώρα) που θέλω για να αποθηκεύσω τα δεδομένα από τα αρχεία. */


int *plithos_mathimaton_ana_spoudasti = new int[spoudastes]; /* Δημιουργία δυναμικού πίνακα. */
vector < int > ta_mathimata_ana_spoudasti[spoudastes]; /* Δημιουργία vector που περιέχει vectors ακεραίων. */

int *plithos_spoudaston_ana_mathima = new int[mathimata]; /* Δημιουργία δυναμικού πίνακα. */
vector < int > oi_spoudastes_ana_mathima[mathimata]; /* Δημιουργία vector που περιέχει vectors ακεραίων. */





/* ===================================== Φόρτωση δεδομένων από τα .CRS αρχεία . ===================================== */
ifstream fp; /* Ρεύμα εισόδου ( I(N)fstream ) */

fp.open(crs_file_name); /* Άνοιγμα αρχείων crs για ανάγνωση. */

/* ===================== Έλεγχος ανοίγματος αρχείου ===================== */
if ( !fp )
	{
	cout << "Σφάλμα : Το αρχείο δεν μπόρεσε να ανοίξει." << endl;
	return -1;
	}
/* ===================== -------------------------- ===================== */

	
int i = 1; /* Από την δεύτερη (1) θέση του πίνακα. */
while ( getline(fp, line_buffer)  ) /* Διαβάζω γραμμή γραμμή και το περιεχόμενο της γραμμής το πετάω σε ένα buffer. */
	{
	
	temp[0] = split(line_buffer) ;  /* Αποθηκεύω το vector σε ένα προσωρινό vector.  */
	plithos_spoudaston_ana_mathima[i] = temp[0][1] ; /* Παίρνω από το μοναδικό (0) vector που έχω το δεύτερο (1) στοιχείο του. */
	i++;
	}
	
cout << "Πλήθος σπουδαστών ανά μάθημα : " << endl;
print_array(plithos_spoudaston_ana_mathima, mathimata);


fp.close(); /* Κλείσιμο αρχείου. */



/* ----------------------------- Τέλος φορτώματος δεδομένων από .CRS αρχείο. ----------------------------- */





/* ===================================== Φόρτωση δεδομένων από τα .STU αρχεία . ===================================== */

fp.open(stu_file_name); /* Άνοιγμα αρχείων stu για ανάγνωση. */


/* ===================== Έλεγχος ανοίγματος αρχείου ===================== */
if ( !fp )
	{
	cout << "Σφάλμα : Το αρχείο δεν μπόρεσε να ανοίξει." << endl;
	return -1;
	}
/* ===================== -------------------------- ===================== */

	
i = 1; /* Από την δεύτερη (1) θέση του πίνακα. */
while ( getline(fp, line_buffer)  ) /* Διαβάζω γραμμή γραμμή και το περιεχόμενο της γραμμής το πετάω σε ένα buffer. */
	{

	plithos_mathimaton_ana_spoudasti[i] = split(line_buffer).size() ;
	
	ta_mathimata_ana_spoudasti[i] = split(line_buffer) ;  /* Αποθηκεύω το vector σε ένα προσωρινό vector.  */
	
	i++;
	
	}



fp.close(); /* Κλείσιμο αρχείου. */

cout << "\n\n\n\n\n\n\n\n\n\n\n\nΠλήθος μαθημάτων ανα σπουδαστή : " << endl;
print_array(plithos_mathimaton_ana_spoudasti, spoudastes);
cout << "\n\n\n\n\n\n\n\n\n\n\n\nΤα μαθήματα ανα σπουδαστή : " << endl;
print_vec_arry(ta_mathimata_ana_spoudasti, spoudastes);

/* ----------------------------- Τέλος φορτώματος δεδομένων από .STU αρχείο. ----------------------------- */




/* Και πάμε τώρα εφόσον έχουμε φορτώσει τα δεδομένα μας να παίξουμε με τα ερωτήματα. ;) */
/* ... */



/* Απελευθέρωση μνήμης από το heap. */
delete [] plithos_mathimaton_ana_spoudasti;
delete [] plithos_spoudaston_ana_mathima;

return 0;
}
