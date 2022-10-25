#include "empresa.h"

bool comparaHoras(Empleado e1, Empleado e2){
    return e1.getHorasTrabajadas() > e2.getHorasTrabajadas();
}

Empresa::Empresa(){}

void Empresa::generarArchivo(){
    srand(time(nullptr));

    std::vector<char*> nombres = {(char*)"Facu <El Profe>", (char*)"Pablo", (char*)"Tomas", (char*)"Tomas", (char*)"Joaco", (char*)"Franco", (char*)"Nico", (char*)"Gonza"};
    std::vector<char*> apellidos = {(char*)"Ferrero", (char*)"Beckmann", (char*)"Godoy", (char*)"Bava", (char*)"Martinez", (char*)"Ruggeri", (char*)"Sarli", (char*)"Fontana"};
    std::vector<char*> dni = {(char*)"1111111", (char*)"2222222", (char*)"3333333", (char*)"4444444", (char*)"5555555", (char*)"6666666", (char*)"7777777", (char*)"8888888"};

    strEmpleado empleado;
    std::fstream archivoEmp("empleados.bin", std::ios::binary | std::ios::out);

    for (int i = 0; i < 8; i++){
        strcpy_s(empleado.dni, dni[i]);
        strcpy_s(empleado.nombre, nombres[i]);
        strcpy_s(empleado.apellido, apellidos[i]);

        archivoEmp.write((char*)&empleado, sizeof(strEmpleado));
    }
    archivoEmp.close();

    std::fstream archivoHor("horas.bin", std::ios::binary | std::ios::out);
    strTiempo tiempo;

    for (int i = 0; i < 30; i++){
        strcpy_s(tiempo.dni, dni[((i % 8) + 8) % 8]);
        tiempo.horas = rand() % 10 + 1;

        archivoHor.write((char*)&tiempo, sizeof(strTiempo));
    }

    archivoHor.close();

}

void Empresa::cargarMapa(){
    strTiempo tiempo;
    std::fstream archivoHor("horas.bin", std::ios::binary | std::ios::in);

    while (archivoHor.read((char*)&tiempo, sizeof(strTiempo))){
        std::string key(tiempo.dni);
        this->mapaDNIHORAS[key] += tiempo.horas;
    }

    archivoHor.close();
}

void Empresa::cargarEmpleados(){
    strEmpleado empStr;
    std::fstream archivoEmp("empleados.bin", std::ios::binary | std::ios::in);

    cargarMapa();

    while (archivoEmp.read((char*)&empStr, sizeof(strEmpleado))){
        std::string dni(empStr.dni);
        std::string nombre(empStr.nombre);
        std::string apellido(empStr.apellido);
        Empleado empleado(dni, nombre, apellido, this->mapaDNIHORAS[empStr.dni]);
        this->empleados.push_back(empleado);
    }

    archivoEmp.close();
}

void Empresa::generarTxt(){
    std::fstream archivoEmp("informe.txt", std::ios::out);

    for (auto emp : this->empleados){
        archivoEmp << emp.getNombre() << " " << emp.getApellido() << " HRS: " << emp.getHorasTrabajadas() << "\n";
    }

    archivoEmp.close();
}

std::vector<Empleado> Empresa::getMayores(){
    sort(this->empleados.begin(), this->empleados.end(), comparaHoras);
    std::vector<Empleado> mayores;
    int mayor = this->empleados[0].getHorasTrabajadas();

    for (int i = 0; i < this->empleados.size(); i++){
        if (this->empleados[i].getHorasTrabajadas() == mayor){
            mayores.push_back(this->empleados[i]);
        } else {
            i = this->empleados.size();
        }
    }
    return mayores;
}

std::vector<Empleado> Empresa::getMenores(){
    sort(this->empleados.begin(), this->empleados.end(), comparaHoras);
    std::vector<Empleado> menores;
    int menor = this->empleados[this->empleados.size() - 1].getHorasTrabajadas();

    for (int i = this->empleados.size() - 1; i > 0; i--){
        if (this->empleados[i].getHorasTrabajadas() == menor){
            menores.push_back(this->empleados[i]);
        } else {
            i = 0;
        }
    }
    return menores;
}
