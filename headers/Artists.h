#ifndef C202A63F_EF6B_4F3E_984A_1E22217193F8
#define C202A63F_EF6B_4F3E_984A_1E22217193F8
using namespace std;

//! Arrays com tamanho ainda a ser discutido
struct Artists{

    string id;
    float followers;
    char genres[100]; //!
    char name[200];//!
    int popularity;

};

void salvarArtistBin(ofstream &arq, Artists artist);

void createArtist(ofstream &arq, string id, float followers, char genres[], char name[], int popularity);

Artists returnArtist(ifstream &arq, int n);

int nRegistrosArtists(ifstream &arq);

Artists *returnVetArtists(ifstream &arq, int nQuantidade);




//todo retornar n artist


#endif /* C202A63F_EF6B_4F3E_984A_1E22217193F8 */
