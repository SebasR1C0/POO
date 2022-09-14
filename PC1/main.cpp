#include "util.h"
class CVector {
	vector <CDonaciones*> vec;
	CMonto* obj1;
public:
	CVector() {}
	~CVector() {}
	void agregar(double monto) {
		CDonaciones* obj = new CDonaciones(monto);
		vec.push_back(obj);
	}
	void cero() {
		for (int i = 0; i < vec.size(); i++) {
			vec[i]->setdonaS(0);
			vec[i]->setdonaP(0);
			vec[i]->setdonaI(0);
		}
	}
	void valores() {
		double a = 0, b = 0, c = 0;
		for (int i = 0; i < vec.size(); i++) {
			a += vec[i]->getdonaS();
			b += vec[i]->getdonaP();
			c += vec[i]->getdonaI();
		}
		CDonaciones* obj = new CDonaciones(a, b, c);
		obj1->datos(*obj);
	}
};
void menu() {
	cout << "1. Colocar monto" << endl;
	cout << "2. Poner todas las secciones en 0" << endl;
	cout << "3. Listar valores" << endl;
}
int main() {
	srand(time(NULL));
	int opcion, monto;
	CVector* objVector = new CVector();

	while (true) {
		menu(); cout << "Ingrese opcion: "; cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Ingrese el monto: "; cin >> monto;
			objVector->agregar(monto);
			cout << "SE AGREGO CON EXITO";
			break;
		case 2:
			objVector->cero();
			cout << "TODOS LOS MONTOS DE LAS SECCIONES SON 0";
			break;
		case 3:
			cout << "Lista de Valores" << endl;
			objVector->valores();
			_getch();
			break;
		}
		Sleep(200);
		system("cls");
	}
	return 0;
}
