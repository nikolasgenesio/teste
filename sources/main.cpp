#include <iostream>
#include <fstream>
#include <string.h>
#include "Artists.h"
#include "Tracks.h"
#include <ctime>

using namespace std;

//Retornar numero aleatorio
int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int arqc, char *arqv[])
{
    ifstream arq("track.bin", ios_base ::in | ios_base ::out | ios_base ::app);
    ifstream arq2("artist.bin", ios_base ::in | ios_base ::out | ios_base ::app);

    int tam = nRegistrosTracks(arq);
    int aux, aux2;
    char resposta;
    cout << "Como voce gostaria de visualizar os dados? \n C para console\n F para arquivo" << endl;
    cin >> resposta;

    //verificar qual opcao foi escolhida
    if (resposta == 'C' || resposta == 'c')
    {
        for (int i = 0; i < 10; i++)
        {
            aux = numAleatorio(0, tam);
            Tracks tracks;
            tracks = returnTrack(arq, aux);

            //tamanho do arquivo artista
            aux2 = nRegistrosArtists(arq2);

            string id = tracks.id_artists;

            for (int j = 0; j < aux2; j++)
            {
                Artists artists;
                artists = returnArtist(arq2, aux2);
                if (id.compare(artists.id) == 0)
                {
                    cout << "Artista = [Id: " << artists.name << " Seguidores: " << artists.followers << " Genero: " << artists.genres << " Nome: " << artists.name << " Popularidade: " << artists.popularity
                         << "] Musica = [Id :" << tracks.id << " Nome: " << tracks.name << " Popularidade: " << tracks.popularity << " Duracao: " << tracks.duration_ms << " Explicito: " << tracks.is_explicit << " Data de Lancamento: " << tracks.release_date << " Dancabilidade: " << tracks.danceability << " Energia: " << tracks.energy << " Chave: " << tracks.key << " Volume: " << tracks.loudness << " Modo: " << tracks.mode << " Discurso: " << tracks.speechiness << " Acustico: " << tracks.acousticness << " Instrumental: " << tracks.instrumentalness << " Vivacidade: " << tracks.liveness << " Valencia: " << tracks.valence << " Tempo: " << tracks.tempo << " Assinatura de tempo: " << tracks.time_signature << "]\n";
                }
            }
        }
    }
    else if (resposta == 'F' || resposta == 'f')
    {
        std::ofstream outFile;
        outFile.open("Texto.txt", ios::out);
        if (!outFile)
            return 0;
        
        for (int i = 0; i < 100; i++)
        {
            aux = numAleatorio(0, tam);
            Tracks tracks;
            tracks = returnTrack(arq, aux);
            aux2 = nRegistrosArtists(arq2);

            string id = tracks.id_artists;

            for (int j = 0; j < aux2; j++)
            {
                Artists artists;
                artists = returnArtist(arq2, aux2);
                if (id.compare(artists.id) == 0)
                {
                    outFile << "Artista = [Id: " << artists.name << " Seguidores: " << artists.followers << " Genero: " << artists.genres << " Nome: " << artists.name << " Popularidade: " << artists.popularity
                         << "] Musica = [Id :" << tracks.id << " Nome: " << tracks.name << " Popularidade: " << tracks.popularity << " Duracao: " << tracks.duration_ms << " Explicito: " << tracks.is_explicit << " Data de Lancamento: " << tracks.release_date << " Dancabilidade: " << tracks.danceability << " Energia: " << tracks.energy << " Chave: " << tracks.key << " Volume: " << tracks.loudness << " Modo: " << tracks.mode << " Discurso: " << tracks.speechiness << " Acustico: " << tracks.acousticness << " Instrumental: " << tracks.instrumentalness << " Vivacidade: " << tracks.liveness << " Valencia: " << tracks.valence << " Tempo: " << tracks.tempo << " Assinatura de tempo: " << tracks.time_signature << "]\n";
                }
            }
        }
        outFile.close();
    }
    else
    {
        cout << "Opcao Invalida" << endl;
    }
    arq.close();
    arq2.close();

    //colinha do meu endereço     /mnt/c/Users/KleitonEwerton/Documents/DEV-c/Trabalho_Pratico/trabalho-pratico-1-grupo04/
    //* nome da pasta é o arqv[1]

    //!############################################ Teste de tudo tracks

    // copiando o nome da pasta para concatenar na abertura do arquivo
    // char pasta[200];
    // strcpy(pasta, arqv[1]);
    // ofstream arq(strcat(pasta,"tracks.bin"), ios_base::out | ios_base::binary | ios_base::app);

    // char pasta1[200];
    // strcpy(pasta1, arqv[1]);
    // ifstream arq1(strcat(pasta1,"tracks.bin"), ios_base::out | ios_base::binary | ios_base::app);

    // cout << nRegistrosTracks(arq1) << endl;

    // char id1[50] = "0000005";
    // char id2[50] = "0000002";
    // char name[200] = "feliz mais triste";
    // int popularity = 3;
    // int duration_ms = 232323;
    // bool is_explicit = 1;
    // char artists[400] = "Kleiton Eww";
    // char id_artists[400] = "0000000 0000001 0000002 0000003 0000004 0000006";
    // char release_date[20] = "23-06-3250";
    // float danceability = 3.4;
    // float energy = 4.7;
    // int key = 9;
    // float loudness = 3.5;
    // bool mode = 1;
    // float speechiness = 9.0;
    // float acousticness = 6.3;
    // float instrumentalness = 2.3;
    // float liveness = 3.4;
    // float valence = 2.4;
    // float tempo = 23232.4;
    // int time_signature = 4;

    // createTrack(arq,id1,name,popularity, duration_ms,is_explicit, artists,id_artists,release_date,danceability,
    //             energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,
    //             tempo,time_signature);
    // createTrack(arq,id2,name,popularity, duration_ms,is_explicit, artists,id_artists,release_date,danceability,
    //             energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,
    //             tempo,time_signature);

    // arq.close();
    // arq1.close();

    //!############################ Fim de teste em tracks

    // Teste nos modulos com vetor do track
    // char pasta1[200];
    // strcpy(pasta1, arqv[1]);
    // ifstream arq1(strcat(pasta1,"tracks.bin"), ios_base::out | ios_base::binary | ios_base::app);

    // cout << nRegistrosTracks(arq1) << endl;

    // Tracks *tracks = new Tracks[5];
    // tracks = returnVetTracks(arq1,5);
    // for(int i=0; i<5;i++)
    //     cout << tracks[i].id << endl;

    // delete [] tracks;

    //!  Testando tudo de artist
    //copiando o nome da pasta para concatenar na abertura do arquivo
    // char pasta[200];
    // strcpy(pasta, arqv[1]);
    // ofstream arq(strcat(pasta,"artist.bin"), ios_base::out | ios_base::binary | ios_base::app);

    // char pasta1[200];
    // strcpy(pasta1, arqv[1]);
    // ifstream arq1(strcat(pasta1,"artist.bin"), ios_base::out | ios_base::binary | ios_base::app);
    // cout << nRegistrosArtists(arq1) << endl;

    // char id[50] = "000000031";
    // char id1[50] = "000000402";
    // float followers = 3.2;
    // char generes[50] = "sadwedasad";
    // char name[50] = "dfdfgdssd";
    // int popularity = 4;

    // createArtist(arq, id, followers, generes, name, popularity);
    // createArtist(arq, id, followers, generes, name, popularity);
    // Artists *artists = new Artists[5];
    // artists = returnVetArtists(arq1, 5);
    // cout << artists[2].id << endl;
    // arq.close();
    // cout << nRegistrosArtists(arq1) << endl;
    // arq1.close();

    return 0;
}