#include <iostream>

using namespace std;

/*
- Créer 3 classes : Quadrupede, Chat et Chien et dériver les deux dernières de la première.
- Ajouter un attribut string ‘nom‘ à Quadrupede ainsi que ses getters et setters.
- Ajouter une méthode speak aux 3 classes avec pour seul code un ‘cout<<‘ qui est sensé refléter le cri de 
l’animal.
- Instancier deux chats et deux chiens à l’aide de pointeurs de l'opérateur new ;
- Déclarer un tableau de n pointeurs de Quadrupede :
- Quadrupede *quadrupede[n];
- Utiliser une boucle for pour parcourir le vecteur afin d’appeler à chaque fois la méthode speak.
- Tester votre code de deux manières : avec ou sans le mot virtual devant la méthode speak de la classe Quadrupede;
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