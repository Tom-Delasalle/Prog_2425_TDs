#include <iostream>

using namespace std;

/*
- Cr�er 3 classes : Quadrupede, Chat et Chien et d�river les deux derni�res de la premi�re.
- Ajouter un attribut string �nom� � Quadrupede ainsi que ses getters et setters.
- Ajouter une m�thode speak aux 3 classes avec pour seul code un �cout<<� qui est sens� refl�ter le cri de 
l�animal.
- Instancier deux chats et deux chiens � l�aide de pointeurs de l'op�rateur new ;
- D�clarer un tableau de n pointeurs de Quadrupede :
- Quadrupede *quadrupede[n];
- Utiliser une boucle for pour parcourir le vecteur afin d�appeler � chaque fois la m�thode speak.
- Tester votre code de deux mani�res : avec ou sans le mot virtual devant la m�thode speak de la classe Quadrupede;
*/

class Quadrupede {

public:
	Quadrupede(const string &in_nom) : nom(in_nom) {
		cout << "Naissance d'un quadripede" << endl;
	}
	~Quadrupede() {}
	virtual void speak() = 0;
	const string& getNom() const {
		return nom;
	}
	void setNom(const string &nom) {
		this->nom = nom;
	}
protected:
	string nom;

};

class Chien : public Quadrupede {
public:
	Chien(const string &in_nom) : Quadrupede(in_nom) {
		cout << "Naissance d'un chien." << endl;
	}
	~Chien() {}
	void speak() { cout << "Ouaf ouaf et pis ouaf" << endl; }
};

class Chat : public Quadrupede {
public:
	Chat(const string& in_nom) : Quadrupede(in_nom) {
		cout << "Naissance d'un chat." << endl;
	}
	~Chat() {}
	void speak() { cout << "Miaou et pis c'est tout." << endl; }
};

int main() {



	return EXIT_SUCCESS;

}