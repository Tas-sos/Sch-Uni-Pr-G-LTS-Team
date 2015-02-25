#include <sstream> /* Για το stringstream */
#include <vector>

using namespace std;


vector <int> split (string line_buffer );
/* Συνάρτηση η οποία :
	- Παίρνει : 
		Ένα STRING ( από αρχείο κυρίως ) που περιέχει μέσα ΑΡΙΘΜΟΎΣ χωρισμένους μεταξύ τους με κενά.
	- Επιστρέφει : 
		Ένα διάνυσμα ( vector ) που περιέχει η κάθε θέση του, τους αριθμούς του string σε ακέραια μορφή.
*/

void print_vec_arry (vector <int> *ela ,int thesis_pinaka);
/* Συνάρτηση η οποία : 
	- Παίρνει :
			- Ένα δείκτη τύπο ακέραιου vector - array .
			- Ένα ακέραιο που αναφέρει τις θέσεις του πίνακα.
	- Επιστρέφει : Την εμφάνιση όλων των τιμών σε κάθε vector που περιέχεται στο vector - array .
*/




/* ================================  Split Function  ================================ */

vector <int> split (string line_buffer ) 
	{
	 /* Δημιουργούμε ένα νέο ρεύμα. */
	stringstream new_stream_by_line_buffer;
	
	/* Δημιουργία νέου προσωρινού string. */
	string packet_buffer;
	
	new_stream_by_line_buffer.str(line_buffer); /* Δίνω στο ρεύμα την string -αυστηρά- μορφή του string που διαβάζω σε κάθε γραμμή. Αυτό το κάνω για να εποφελειθώ των ιδιοτήτων που μου προσφέρει ένα ρεύμα.  
	Έτσι κάθε γραμμή που διαβάζω μέσω του ρεύματος εισόδου που έχω κάνει για να διαβάζω από το αρχείο και την αποθηκεύω στο string line_buffer, το stringάκι έπειτα αυτό το δίνω ξανά σε ένα καινούριο προσωρινό ρεύμα. */
	
	vector <int> temp_vec ; /* Δημιουργία vector . */
	
	while ( new_stream_by_line_buffer >> packet_buffer )
		{
		
		
		temp_vec.push_back( atoi(packet_buffer.c_str()) ); /* Εκχωρώ την ακέραια τιμή του string στο ακέραιων vector μου. */
				
		}

	return temp_vec;
	temp_vec.clear(); /* Διαγράφω - καθαρίζω το vector . */

	}
/* =========================================  Τέλος split  ========================================= */



/* ================================================================================================== */



/* =============================== Print Values of Vectors in Vector =============================== */
void print_vec_arry (vector <int> *ela ,int thesis_pinaka)
	{
	for (int i = 0 ; i < thesis_pinaka; i++)
			{
			
			for (int j = 0; j < ela[i].size(); j++)
				cout  << ela[i][j] << " " ;
			
			cout << endl;
			}
	}

/* =============================== End ~ Print Values of Vectors in Vector =============================== */
















