/*
Nama    : Alvin
NPM     : 140810180013
Kelas   : A
Tugas   : Stable Matching Problem
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const char *men_data[][6] = {
    { "victor", "bertha", "amy", "diane", "erika", "clare" },
    { "wyatt",  "diane", "bertha", "amy", "clare", "erika" },
    { "xavier", "bertha", "erika", "clare", "diane", "amy" },
    { "yancey", "amy", "diane", "clare", "bertha", "erika" },
    { "zeus",   "bertha", "diane", "amy", "erika", "clare" }
};
const char *women_data[][6] = {
     { "amy",    "zeus", "victor", "wyatt", "yancey", "xavier" },
    { "bertha", "xavier", "wyatt", "yancey", "victor", "zeus" },
    { "clare",  "wyatt", "xavier", "yancey", "zeus", "victor" },
    { "diane",  "victor", "zeus", "yancey", "xavier", "wyatt" },
    { "erika",  "yancey", "wyatt", "zeus", "xavier", "victor" }
};

typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap ;
typedef map<string, string> Pasangan;

bool prefers(const PrefList &prefer, const string &first, const string &second )//membedakan list pertama sebagai yang punya refernesi dan kedua sebagai preferensinya
{
    for (PrefList::const_iterator it = prefer.begin(); it != prefer.end(); ++it)
    {
        if (*it == first) return true;//orang yang punya referensi
        if (*it == second) return false;//referensi
    }
    return false;
}

int main(){
    PrefMap men_pref, women_pref;
    queue<string> bachelors;

    //inisialisasi data
    for (int i = 0; i < 5; ++i)//orang yang punya preferensi
    {
        for (int j = 1; j<6; ++j)//referensi
        {
            men_pref[ men_data[i][0]].push_back(men_data[i][j]);
             women_pref[ women_data[i][0]].push_back(women_data[i][j]);
        }
        bachelors.push(men_data[i][0]);
    }

    Pasangan engaged;

    cout<<"PROSES MENCOCOKKAN :\n";
    while (!bachelors.empty()){
        const string &suitor = bachelors.front();
        const PrefList &preflist = men_pref[suitor];
		
        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it){
            const string &bride = *it;
			
			//Wanita single
            if (engaged.find(bride) == engaged.end()){
                cout << "\t" << bride << " dan " << suitor << "\n";
				//Dipasangkan
                engaged[bride] = suitor;
                break;
            }
			
            const string &groom = engaged[bride];
			
            if (prefers(women_pref[bride], suitor, groom)){
                cout << "\t" << bride << " putus dengan " << groom << " untuk " << suitor << "\n";
                bachelors.push(groom); //lepas mantan
                engaged[bride] = suitor; //pilih pasangan baru
                break;
            }
        }
        bachelors.pop();
    }
 
    cout << "HASIL PASANGAN :\n";
    for (Pasangan::const_iterator it = engaged.begin(); it != engaged.end(); ++it){
        cout << "\t" << it->first << " dan " << it->second << "\n";
    }
 
   

}
