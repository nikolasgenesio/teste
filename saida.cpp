#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char argv)
{
    /*
    Perguntas:
    1 - como é o arquivo bin?
    2 - Kleiton
    */

    char resposta;
    cout << "Como voce gostaria de visualizar os dados? \n C para console\n F para arquivo" << endl;
    cin >> resposta;

    if (resposta == 'C' || resposta == 'c')
    {
        for (int i = 0; i < 10; i++)
        {
            /*
            id artists = id tracks
            */
            cout << "Artista = [Id: " << i << " Seguidores: " << i << " Genero: " << i << " Nome: " << i << " Popularidade: " << i
                 << "] Musica = [Id :" << i << " Nome: " << i << " Popularidade: " << i << " Duracao: " << i << " Explicito: " << i << " Data de Lancamento: " << i << " Dancabilidade: " << i << " Energia: " << i << " Chave: " << i << " Volume: " << i << " Modo: " << i << " Discurso: " << i << " Acustico: " << i << " Instrumental: " << i << " Vivacidade: " << i << " Valencia: " << i << " Tempo: " << i << " Assinatura de tempo: " << i << "]\n";
        }
    }
    else if (resposta == 'F' || resposta == 'f')
    {
        //criando arquivo
        std::ofstream outFile;
        outFile.open("Texto.txt", ios::out);
        if (!outFile)
            return 0;
        //escrevendo no arquivo
        for (int i = 0; i < 100; i++)
        {
            /*
            id artists = id tracks
            */
            outFile << "Artista = [Id: " << i << " Seguidores: " << i << " Genero: " << i << " Nome: " << i << " Popularidade: " << i
                    << "] Musica = [Id :" << i << " Nome: " << i << " Popularidade: " << i << " Duracao: " << i << " Explicito: " << i << " Data de Lancamento: " << i << " Dancabilidade: " << i << " Energia: " << i << " Chave: " << i << " Volume: " << i << " Modo: " << i << " Discurso: " << i << " Acustico: " << i << " Instrumental: " << i << " Vivacidade: " << i << " Valencia: " << i << " Tempo: " << i << " Assinatura de tempo: " << i << "]\n";
        }
        outFile.close();
    }
    else
    {
        cout << "Opcao Invalida" << endl;
    }
    return 0;
}