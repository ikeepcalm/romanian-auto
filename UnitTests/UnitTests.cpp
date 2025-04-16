#include "CppUnitTest.h"
#include<math.h>
#define private public
#include "..//Tema2_ID/Source.cpp"
#undef private

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestareConstructorImplicit)
		{
			Autoturism a;
			Assert::IsTrue(a.marca == "Necunoscuta",
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(a.model == "Necunoscut",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(a.putere == 0,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(a.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
			Assert::IsTrue(a.distanteParcurse == NULL,
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(a.nrDrumuri == 0,
				L"Constructorul nu initializeaza corect numarul de drumuri");
		}

		TEST_METHOD(_02TestareConstructorCu3Parametri)
		{
			Autoturism a("Dacia", "Logan", 60);
			Assert::IsTrue(a.marca == "Dacia",
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(a.model == "Logan",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(a.putere == 60,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(a.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
			Assert::IsTrue(a.distanteParcurse == NULL,
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(a.nrDrumuri == 0,
				L"Constructorul nu initializeaza corect numarul de drumuri");
		}

		TEST_METHOD(_03TestareConstructorCu4Parametri)
		{
			float v[] = { 200.5f, 200.3f, 100.2f};

			Autoturism a("Dacia", "Logan", NULL, -2);
			Assert::IsTrue(a.marca == "Dacia",
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(a.model == "Logan",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(a.putere == 0,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(a.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
			Assert::IsTrue(a.distanteParcurse == NULL,
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(a.nrDrumuri == 0,
				L"Constructorul nu initializeaza corect numarul de drumuri");

			Autoturism b("Dacia", "Logan", v, 3);
			Assert::IsTrue(b.marca == "Dacia",
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(b.model == "Logan",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(b.putere == 0,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(b.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
			Assert::IsTrue(b.distanteParcurse != v,
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[0] == v[0],
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[1] == v[1],
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[2] == v[2],
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(b.nrDrumuri == 3,
				L"Constructorul nu initializeaza corect numarul de drumuri");
		}

		TEST_METHOD(_04TestareDestructor)
		{
			float v[] = { 200.5f, 200.3f, 100.2f };
			Autoturism* pa = new Autoturism("Test", "test", v, 3);
			float* pointer = pa->distanteParcurse;
			delete pa;
			Assert::IsTrue(*pointer != 200.5f,
				L"Destructorul nu sterge zona de memorie alocata dinamic");
		}

		TEST_METHOD(_05TestareConstructorDeCopiere)
		{
			float v[] = { 200.5f, 200.3f, 100.2f };

			Autoturism a("Renault", "Sandero", v, 3);
			a.putere = 7000;
			a.pret = 9000;
			Autoturism b = a;
			Assert::IsTrue(b.marca == a.marca,
				L"Constructorul nu copiaza corect marca");
			Assert::IsTrue(b.model == a.model,
				L"Constructorul nu copiaza corect modelul");
			Assert::IsTrue(b.putere == a.putere,
				L"Constructorul nu copiaza corect puterea");
			Assert::IsTrue(abs(b.pret - a.pret) < 0.01,
				L"Constructorul nu copiaza corect pretul");
			Assert::IsTrue(b.distanteParcurse != a.distanteParcurse,
				L"Constructorul nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[0] == a.distanteParcurse[0],
				L"Constructorul nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[1] == a.distanteParcurse[1],
				L"Constructorul nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[2] == a.distanteParcurse[2],
				L"Constructorul nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.nrDrumuri == a.nrDrumuri,
				L"Constructorul nu copiaza corect numarul de drumuri");
		}

		TEST_METHOD(_06TestareMetodeDeAccesMarca)
		{
			Autoturism a;
			Assert::IsTrue(a.getMarca() == "Necunoscuta",
				L"Getter-ul nu returneaza valoarea corecta");
			a.setMarca("ab");
			Assert::IsTrue(a.getMarca() == "Necunoscuta",
				L"Setter-ul nu realizeaza corect validarea");
			a.setMarca("ABC");
			Assert::IsTrue(a.getMarca() == "ABC",
				L"Setter-ul nu functioneaza corect");
		}

		TEST_METHOD(_07TestareGetterDistante)
		{
			float v[] = { 200.5f, 200.3f, 100.2f };

			Autoturism a("Renault", "Sandero", v, 3);
			Assert::IsTrue(a.getNrDrumuri() == 3,
				L"Getter numar drumuri gresit");
			Assert::IsTrue(a.getDistanteParcurse() != a.distanteParcurse,
				L"Getter pentru distante parcurse returneaza o copie superficiala");
			float* result = a.getDistanteParcurse();
			Assert::IsTrue(result[0] == a.distanteParcurse[0],
				L"Copia returnata nu este corecta");
			Assert::IsTrue(result[1] == a.distanteParcurse[1],
				L"Copia returnata nu este corecta");
			Assert::IsTrue(result[2] == a.distanteParcurse[2],
				L"Copia returnata nu este corecta");

			Autoturism b("Renault", "Sandero", NULL, 0);
			Assert::IsTrue(b.getNrDrumuri() == 0,
				L"Getter numar drumuri gresit");
			Assert::IsTrue(b.getDistanteParcurse() == NULL,
				L"Getter pentru distante parcurse nu valideaza NULL");
		}

		TEST_METHOD(_08TestareSetterDistante)
		{
			float v[] = { 200.5f, 200.3f, 100.2f };
			float w[] = { 125.2f, 99.3f };

			Autoturism a("Renault", "Sandero", v, 3);
			a.setDistante(w, 2);
			
			Assert::IsTrue(a.nrDrumuri == 2,
				L"Setter gresit");
			Assert::IsTrue(a.distanteParcurse != w,
				L"Setter-ul pentru distante realizeaza o copie superficiala");
			float* result = a.getDistanteParcurse();
			Assert::IsTrue(w[0] == a.distanteParcurse[0],
				L"Copia returnata nu este corecta");
			Assert::IsTrue(w[1] == a.distanteParcurse[1],
				L"Copia returnata nu este corecta");
		}

		TEST_METHOD(_09TestareMetodeAccesTaraProductie)
		{
			Autoturism a;
			a.setTaraDeProductie("Romania");

			Assert::IsTrue(strcmp(a.getTaraDeProductie(), "Romania") == 0,
				L"Setter gresit");
			const char* tara = "Republica Moldova";
			a.setTaraDeProductie(tara);
			Assert::IsTrue(strcmp(a.getTaraDeProductie(), tara) == 0,
				L"Setter gresit");
			Assert::IsTrue(a.getTaraDeProductie() != tara,
				L"Getter-ul returneaza o copie superficiala");
		}

		TEST_METHOD(_10TestareGestionareCampNou)
		{
			Autoturism a;
			a.setTaraDeProductie("Franta");
			Autoturism b = a;

			Assert::IsTrue(a.getTaraDeProductie() != b.getTaraDeProductie(),
				L"Constructorul de copiere nu copiaza corect tara");
			Assert::IsTrue(strcmp(a.getTaraDeProductie(), b.getTaraDeProductie()) == 0,
				L"Constructorul de copiere nu copiaza corect tara");

			Autoturism* pa = new Autoturism();
			pa->setTaraDeProductie("Germania");
			char* litera = pa->AdresaInceputTaraDeProductie();
			delete pa;
			Assert::IsTrue(*litera != 'G',
				L"Destructorul nu sterge corect tara de productie");
		}

		TEST_METHOD(_11TestareOperatorAtribuire)
		{
			float v[] = { 200.5f, 200.3f, 100.2f };

			Autoturism a("Renault", "Sandero", v, 3);
			a.putere = 7000;
			a.pret = 9000;
			Autoturism b;
			b = a;
			Assert::IsTrue(b.marca == a.marca,
				L"Operatorul= nu copiaza corect marca");
			Assert::IsTrue(b.model == a.model,
				L"Operatorul= nu copiaza corect modelul");
			Assert::IsTrue(b.putere == a.putere,
				L"Operatorul= nu copiaza corect puterea");
			Assert::IsTrue(abs(b.pret - a.pret) < 0.01,
				L"Operatorul= nu copiaza corect pretul");
			Assert::IsTrue(b.distanteParcurse != a.distanteParcurse,
				L"Operatorul= nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[0] == a.distanteParcurse[0],
				L"Operatorul= nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[1] == a.distanteParcurse[1],
				L"Operatorul= nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.distanteParcurse[2] == a.distanteParcurse[2],
				L"Operatorul= nu copiaza corect vectorul de distante");
			Assert::IsTrue(b.nrDrumuri == a.nrDrumuri,
				L"Operatorul= nu copiaza corect numarul de drumuri");
			Assert::IsTrue(a.getTaraDeProductie() != b.getTaraDeProductie(),
				L"Operatorul= nu copiaza corect tara");
			/*Assert::IsTrue(strcmp(a.getTaraDeProductie(), b.getTaraDeProductie()) == 0,
				L"Operatorul= nu copiaza corect tara");*/
		}

		TEST_METHOD(_12TestareIdUnic)
		{
			Autoturism::numarAutoturisme = 0;
			Autoturism a;
			Autoturism b("Dacia", "Logan", 60);
			float v[] = { 200.5f, 200.3f, 100.2f };
			Autoturism c("Dacia", "Logan", v, 3);
			Assert::IsTrue(a.serieCaroserie == 1,
				L"Constructorul default nu initializeaza corect serie caroserie");
			Assert::IsTrue(b.serieCaroserie == 2,
				L"Constructorul cu 3 parametri nu initializeaza corect serie caroserie");
			Assert::IsTrue(c.serieCaroserie == 3,
				L"Constructorul cu 4 parametri nu initializeaza corect serie caroserie");
		}

		TEST_METHOD(_13TestareValoreaFlota)
		{
			Autoturism masini[3];
			Autoturism a1, a2, a3;
			a1.pret = 1111.5;
			a2.pret = 2222.5;
			a3.pret = 3333.4;
			masini[0] = a1; masini[1] = a2; masini[2] = a3;
			double rezultat = Autoturism::calcul_valoare_flota(masini, 3);
			Assert::IsTrue(abs(rezultat - 6667.4) < 0.01, L"Functia nu returneza corect valoarea flotei");
		}

		TEST_METHOD(_14TestareMetodaDiscount)
		{
			Autoturism a;
			a.pret = 9876;
			a.discount(0);
			Assert::IsTrue(abs(a.pret - 9876) < 0.01,
				L"Metoda discount accepta valori mai mici de 1");
			a.discount(51);
			Assert::IsTrue(abs(a.pret - 9876) < 0.01,
				L"Metoda discount accepta valori mai mari de 50");
			a.discount(25);
			Assert::IsTrue(abs(a.pret - 7407) < 0.01,
				L"Metoda nu aplica discountul in mod corect");
		}

		TEST_METHOD(_15TestareLocuriLibere)
		{
			Autoturism a1, a2, a3, a4, a5, a6;
			a1.putere = 200;
			a2.putere = 180;
			a3.putere = 120;
			a4.putere = 320;
			a5.putere = 150;
			a6.putere = 90;
			Autoturism*** matrice = new Autoturism * *[3];
			for (int i = 0; i < 3; i++)
			{
				matrice[i] = new Autoturism * [3];
			}
			matrice[0][0] = &a1;
			matrice[0][1] = &a2;
			matrice[0][2] = &a3;
			matrice[1][0] = nullptr;
			matrice[1][1] = &a4;
			matrice[1][2] = &a5;
			matrice[2][0] = nullptr;
			matrice[2][1] = &a6;
			matrice[2][2] = nullptr;

			int** rezultat = locuri_libere(matrice, 3, 3);
			Assert::IsTrue(rezultat[0][0] == 200,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[0][1] == 180,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[0][2] == 120,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][0] == 0,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][1] == 320,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][2] == 150,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][0] == 0,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][1] == 90,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][2] == 0,
				L"Matricea returnata nu are valorile corecte");
		}
	};
}
