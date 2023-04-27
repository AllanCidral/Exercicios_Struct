//FUNCAO:
// gerar um relatorio com nomes, notas e media de alunos de duas turmas, e tambem a media geral da turma.
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stof
#include <iomanip> // setprecision
#define TNOTAS 4 // quantidade de notas
#define TTURMA 20 // tamanho da turma
#define TMAX 10 // nota maxima
using namespace std;

typedef struct {
	string nome;
	float notas[TNOTAS], media;
} Aluno;
typedef struct {
	Aluno turma1[TTURMA], turma2[TTURMA];
	float mediaTurma1, mediaTurma2;
} Turmas;
void leiaNomesT1(Turmas &t1); // le e valida os nomes dos alunos da 1 turma
void leiaNotasT1(Turmas &t1); // le e valida as notas dos alunos da 1 turma
void gerarMediaAlunoT1(Turmas &t1); // gera a media dos alunos da 1 turma
float gerarMediaTurmaT1(Turmas &t1); // gera a media geral da 1 turma
void leiaNomesT2(Turmas &t2); // le e valida os nomes dos alunos da 2 turma
void leiaNotasT2(Turmas &t2); // le e valida as notas dos alunos da 2 turma
void gerarMediaAlunoT2(Turmas &t2); // gera a media dos alunos da 2 turma
float gerarMediaTurmaT2(Turmas &t2); // gera a media geral da 2 turma
void relatorioT1(Turmas &t1); // relatorio da 1 turma
void relatorioT2(Turmas &t2); // relatorio da 2 turma

int main()
{
	Turmas t1, t2;

	leiaNomesT1(t1);
	system("CLS");
	leiaNotasT1(t1);
	system("CLS");
	gerarMediaAlunoT1(t1);
	t1.mediaTurma1 = gerarMediaTurmaT1(t1);
	leiaNomesT2(t2);
	system("CLS");
	leiaNotasT2(t2);
	system("CLS");
	gerarMediaAlunoT2(t2);
	t2.mediaTurma2 = gerarMediaTurmaT2(t2);
	system("CLS");
	relatorioT1(t1);
	relatorioT2(t2);
}
void leiaNomesT1(Turmas &t1) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		t1.turma1[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome do(a) " << i+1 << " aluno(a) da turma 1: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		t1.turma1[i].nome = info;
	}
}
void leiaNotasT1(Turmas &t1) {
	string info = "";
	bool validado;
	int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		for (unsigned short int j = 0; j < TNOTAS; j++) {
			t1.turma1[i].notas[j] = 0.0;
			do {
				do {
					validado = true;
					ponto = 0;
					cout << "Informe a " << j + 1 << " nota do(a) " << t1.turma1[i].nome << ": ";
					getline(cin, info);
					if (info == "") // se a string for vazia
						validado = false;
					else
						for (unsigned short int k = 0; k < info.size(); k++) // verifica posicao a posicao
							if (!isdigit(info.at(k))) { // se nao for digito
								if (isdigit(info.at(k - 1)) and info.at(k) == '.' and ponto == 0) // verifica se ha um ponto antes
									ponto++; // permite somente um ponto
								else
									validado = false;
							}
					if (!validado)
						cout << "Nota invalida, tente novamente." << endl;
				} while (!validado);
				x = stof(info.c_str()); // converte string para float
				if (x > TMAX)
					cout << "Nota invalida, tente novamente." << endl;
			} while (x > TMAX);
			t1.turma1[i].notas[j] = x;
		}
	}
}
void gerarMediaAlunoT1(Turmas &t1) {
	for (unsigned short int i = 0; i < TTURMA; i++) {
		float media = 0.0;
		t1.turma1[i].media = 0.0;
		for (unsigned short int j = 0; j < TNOTAS; j++)
			media += t1.turma1[i].notas[j];
		t1.turma1[i].media = media / TNOTAS;
	}
}
float gerarMediaTurmaT1(Turmas &t1) {
	float media = 0.0;
	for (unsigned short int i = 0; i < TTURMA; i++)
		media += t1.turma1[i].media;
	return media / TTURMA;
}
void relatorioT1(Turmas &t1) {
	cout << "----------------------------------------------\n";
	cout << "Turma 1:\n";
	cout << endl;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		cout << "Aluno(a): " << t1.turma1[i].nome << endl;
		cout << "Notas: ";
		for (unsigned short int j = 0; j < TNOTAS; j++) {
			cout << "[" << fixed << setprecision(2) << t1.turma1[i].notas[j] << "]";
		}
		cout << endl;
		cout << "Media: " << fixed << setprecision(2) << t1.turma1[i].media << endl;
		cout << endl;
	}
	cout << "Media da turma: " << fixed << setprecision(2) << t1.mediaTurma1 << endl;
}
void leiaNomesT2(Turmas &t2) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		t2.turma2[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome do(a) " << i + 1 << " aluno(a) da turma 2: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		t2.turma2[i].nome = info;
	}
}
void leiaNotasT2(Turmas &t2) {
	string info = "";
	bool validado;
	int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		for (unsigned short int j = 0; j < TNOTAS; j++) {
			t2.turma2[i].notas[j] = 0.0;
			do {
				do {
					validado = true;
					ponto = 0;
					cout << "Informe a " << j + 1 << " nota do(a) " << t2.turma2[i].nome << ": ";
					getline(cin, info);
					if (info == "") // se a string for vazia
						validado = false;
					else
						for (unsigned short int k = 0; k < info.size(); k++) // verifica posicao a posicao
							if (!isdigit(info.at(k))) { // se nao for digito
								if (isdigit(info.at(k - 1)) and info.at(k) == '.' and ponto == 0) // verifica se ha um ponto antes
									ponto++; // permite somente um ponto
								else
									validado = false;
							}
					if (!validado)
						cout << "Nota invalida, tente novamente." << endl;
				} while (!validado);
				x = stof(info.c_str()); // converte string para float
				if (x > TMAX)
					cout << "Nota invalida, tente novamente." << endl;
			} while (x > TMAX);
			t2.turma2[i].notas[j] = x;
		}
	}
}
void gerarMediaAlunoT2(Turmas &t2) {
	for (unsigned short int i = 0; i < TTURMA; i++) {
		float media = 0.0;
		t2.turma2[i].media = 0.0;
		for (unsigned short int j = 0; j < TNOTAS; j++)
			media += t2.turma2[i].notas[j];
		t2.turma2[i].media = media / TNOTAS;
	}
}
float gerarMediaTurmaT2(Turmas &t2) {
	float media = 0.0;
	for (unsigned short int i = 0; i < TTURMA; i++)
		media += t2.turma2[i].media;
	return media / TTURMA;
}
void relatorioT2(Turmas &t2) {
	cout << "----------------------------------------------\n";
	cout << "Turma 2:\n";
	cout << endl;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		cout << "Aluno(a): " << t2.turma2[i].nome << endl;
		cout << "Notas: ";
		for (unsigned short int j = 0; j < TNOTAS; j++) {
			cout << "[" << fixed << setprecision(2) << t2.turma2[i].notas[j] << "]";
		}
		cout << endl;
		cout << "Media: " << fixed << setprecision(2) << t2.turma2[i].media << endl;
		cout << endl;
	}
	cout << "Media da turma: " << fixed << setprecision(2) << t2.mediaTurma2 << endl;
	cout << "----------------------------------------------\n";
}

