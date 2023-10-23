#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
private:

    string nome, cpf, convenio; 
    int dia, mes, ano;

public:
    void setNome(string _Nome){
        nome = _Nome;
    }
    string getNome(){
        return nome;
    }
    string getCPF(){
        return cpf;
    }
    void setData (int _dia, int _mes, int _ano){
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }
    string getData(){
       return to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);
    }
    

Paciente(){
    cout << "Digite um nome: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o CPF: " << endl;
    cin >> cpf;
    cout <<"Digite a data de nascimento:" << endl;
    cin >> dia >> mes >> ano;
}
};
/*
class medico {
string nomeMed, CRM, Especialidade;

};*/



int main(){
vector<Paciente> dadosPaciente;
string localPaciente;
int opcao;

do{
cout <<"-----Menu-----"<< endl;
cout <<"1 - Incluir" << endl;
cout <<"2 - Excluir" << endl;
cout <<"3 - Alterar" << endl;
cout <<"4 - Listar" << endl;
cout <<"5 - Localizar" << endl;
cout <<"0 - Sair" << endl;
cin >> opcao;

if (opcao == 1){
    dadosPaciente.push_back(Paciente ());

} else if (opcao == 2){
        cout <<"Digite o CPF do paciente: " << endl;
        cin >> localPaciente;

    //Escolhida a opção excluir, o seu programa deve solicitar o CPF de um paciente e excluí-lo da 
//coleção de pacientes.

} else if (opcao == 3){
    cout <<"Digite o CPF do paciente: " << endl;
    cin >> localPaciente;
    int i = 0, alteraNome, alteraData, dia, mes, ano;
    string nome;
    while (1){

        if (localPaciente == dadosPaciente[i].getCPF()){
            cout << dadosPaciente[i].getNome() <<endl;
            cout << dadosPaciente[i].getCPF() <<endl;
            cout << dadosPaciente[i].getData() <<endl;
        break;
        }

        i++;

        if (i>int(dadosPaciente.size())){
            i=-1;
            cout << "Paciente não encontrado";
            break;
        }
    }
    if (i >= 0){
        cout << "Deseja alterar o nome? digite 1 para sim e 2 para nao: " << endl;
        cin >> alteraNome;
    if (alteraNome == 1){
        cout << "Digite o novo nome: " << endl;
        cin >> nome; 
        dadosPaciente[i].setNome(nome);
    }
    cout << "Deseja alterar a data de nascimento? digite 1 para sim e 2 para nao: " << endl;
    cin >> alteraData;
    if (alteraData == 1){
        cout << "Digite a nova data: " << endl;
        cin >> dia >> mes >> ano; 
        dadosPaciente[i].setData(dia, mes, ano); 
    }
    }

} else if (opcao == 4){
        for(int i = 0; i< int(dadosPaciente.size()); i++){
        cout << dadosPaciente[i].getNome() << endl;
    }

} else if(opcao == 5) {
    cout <<"Digite o CPF do paciente: " << endl;
    cin >> localPaciente;
        for (int i = 0; i< int(dadosPaciente.size()); i++){
            if (localPaciente == dadosPaciente[i].getCPF()){
            cout << dadosPaciente[i].getNome() <<endl;
            cout << dadosPaciente[i].getCPF() <<endl;
            cout << dadosPaciente[i].getData() <<endl;
            break;
            }
        }
}
} while (opcao != 0);
}