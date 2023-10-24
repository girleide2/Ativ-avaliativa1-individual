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
static void incluiPaciente(vector<Paciente> &dadosPaciente){
    dadosPaciente.push_back(Paciente ());
    cout << "----Paciente incluido----" << endl;
}
static void excluiPaciente(vector<Paciente> &dadosPaciente){
    string localPaciente;
    cout <<"Digite o CPF do paciente: " << endl;
    cin >> localPaciente;
    for (size_t i = 0; i < dadosPaciente.size(); i++) {
        if (localPaciente == dadosPaciente[i].getCPF()) {
            dadosPaciente.erase(dadosPaciente.begin() + i);
            cout << "----Paciente excluido----" << endl;
            break;
        }
    }
}
static void alterarPaciente(vector<Paciente> &dadosPaciente){
    string localPaciente;
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
            cout << "----Paciente não encontrado----";
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
        cout << "nome alterado" << endl;
    }
    cout << "Deseja alterar a data de nascimento? digite 1 para sim e 2 para nao: " << endl;
    cin >> alteraData;
    if (alteraData == 1){
        cout << "Digite a nova data: " << endl;
        cin >> dia >> mes >> ano; 
        dadosPaciente[i].setData(dia, mes, ano);
        cout << "Data de nascimento alterada" << endl;
    }
    }
}
static void listaPaciente(vector<Paciente> &dadosPaciente){
    for(int i = 0; i< int(dadosPaciente.size()); i++){
        cout << "----Pacientes disponiveis----" << endl;
        cout << dadosPaciente[i].getNome() << endl;
    }
}
static void localizaPaciente(vector<Paciente> dadosPaciente){
    string localPaciente;
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
static void menuPaciente(vector<Paciente> &dadosPaciente){
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
Paciente::incluiPaciente(dadosPaciente);

} else if (opcao == 2){
Paciente::excluiPaciente(dadosPaciente);

} else if (opcao == 3){
Paciente::alterarPaciente(dadosPaciente);

} else if (opcao == 4){
Paciente::listaPaciente(dadosPaciente);

} else if(opcao == 5){
Paciente::localizaPaciente(dadosPaciente);
}
} while (opcao != 0);
}
};

class Medico {
private:
    string nomeMed, CRM, Especialidade;

public:
    string getNomeMed(){
        return nomeMed;
    }
    string getCRM(){
        return CRM;
    }
    string getEspecialidade(){
        return Especialidade;
    }
    void setNomeMEd(string _NomeMed){
        nomeMed = _NomeMed;
    }
    void setEspecialidade(string _Especialidade){
        Especialidade = _Especialidade;
    }

    Medico(){ 
    cout << "Digite um nome: " << endl;
    cin.ignore();
    getline(cin, nomeMed);
    cout << "Digite o CRM: " << endl;
    cin >> CRM;
    cout <<"Digite a especialidade:" << endl;
    cin.ignore();
    getline(cin, Especialidade);
    }
    static void incluiMedico(vector<Medico> &dadosMedico){
    dadosMedico.push_back(Medico ());
    cout <<"---- Medico incluido----" << endl;
    }

    static void excluiMedico(vector<Medico> &dadosMedico){
        string localMedico;
        cout <<"Digite o CRM do Medico: " << endl;
        cin >> localMedico;
        for (size_t i = 0; i < dadosMedico.size(); i++) {
            if (localMedico == dadosMedico[i].getCRM()) {
                dadosMedico.erase(dadosMedico.begin() + i);
                cout << "----Medico excluido----" << endl;
                break;
            }
        }
    }

    static void alteraMedico(vector<Medico> &dadosMedico){
        string localMedico;
        cout <<"Digite o CRM do Medico: " << endl;
        cin >> localMedico;
        string nome, novEsp;
        int i = 0, alteraNome, alteraEspecialidade;
        while (1){

            if (localMedico == dadosMedico[i].getCRM()){
                cout << dadosMedico[i].getNomeMed() <<endl;
                cout << dadosMedico[i].getCRM() <<endl;
                cout << dadosMedico[i].getEspecialidade() <<endl;
            break;
            }

            i++;

            if (i>int(dadosMedico.size())){
                i=-1;
                cout << "Medico nao encontrado";
                break;
            }
        }
        if (i >= 0){
            cout << "Deseja alterar o nome? digite 1 para sim e 2 para nao: " << endl;
            cin >> alteraNome;
        if (alteraNome == 1){
            cout << "Digite o novo nome: " << endl;
            cin.ignore();
            getline(cin,nome); 
            dadosMedico[i].setNomeMEd(nome);
            cout << "----Nome alterado----" << endl;
        }
            cout << "Deseja alterar a especialidade? digite 1 para sim e 2 para nao: " << endl;
           
            cin >> alteraEspecialidade;
            if (alteraEspecialidade == 1){
            cout << "Digite a nova especialidade: " << endl;
            cin.ignore();
            getline(cin, novEsp); 
            dadosMedico[i].setEspecialidade(novEsp);
            cout << "----Especialidade alterada----" << endl;
        }
        }
    }

    static void listaMedico(vector<Medico> dadosMedico){
        for(int i = 0; i< int(dadosMedico.size()); i++){
            cout << "----Lista de Medicos disponiveis:----" << endl;
            cout << dadosMedico[i].getNomeMed() << endl;
        }
    }

    static void localizaMedico(vector<Medico> dadosMedico){
            string localMedico;
            cout <<"Digite o CRM do paciente: " << endl;
            cin >> localMedico;
            for (int i = 0; i< int(dadosMedico.size()); i++){
                if (localMedico == dadosMedico[i].getCRM()){
                cout << dadosMedico[i].getNomeMed() <<endl;
                cout << dadosMedico[i].getCRM() <<endl;
                cout << dadosMedico[i].getEspecialidade() <<endl;
                break;
                }
            }
    }
    static void menuMedico(vector<Medico> &dadosMedico){
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
    Medico::incluiMedico(dadosMedico);

    }else if (opcao == 2){
    Medico::excluiMedico(dadosMedico);

    } else if (opcao == 3){
    Medico::alteraMedico(dadosMedico);

    } else if (opcao == 4){
    Medico::listaMedico(dadosMedico);

    } else if(opcao == 5) {
    Medico::localizaMedico(dadosMedico);
    }

    } while (opcao != 0); 
    }
};

int main(){
vector<Paciente> dadosPaciente;
vector<Medico> dadosMedico;
int opcao;

do{
    cout << "----- Menu principal-----" << endl;
    cout << "1 - Gestao de Pacientes" << endl;
    cout << "2 - Gestao de Medicos" << endl;
    cout << "0 - Sair" << endl;
    cin >> opcao;
     if (opcao==1){
    Paciente::menuPaciente(dadosPaciente);
     }
     if (opcao==2){
    Medico::menuMedico(dadosMedico);
     }
} while (opcao != 0);
}