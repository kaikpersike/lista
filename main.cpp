#include <iostream>
using namespace std;

struct Funcionario{
    int prontuario;
    string nome;
    double salario;
};

struct Lista{
    Funcionario *dados;
    Lista *prox;
};

Lista* init(){
    return NULL;
}

int isEmpty(Lista *lista){
    return(lista==NULL);
}

// inserir:

Lista* insert(Lista *lista, int prt, string nm, double sal){
    Lista *novo = new Lista();
    novo->dados = new Funcionario();
    novo->dados->prontuario = prt;
    novo->dados->nome = nm;
    novo->dados->salario = sal;
    novo->prox = lista;
    
    return novo;
}

// listar:

void print(Lista* lista) {
	Lista *aux;
	aux = lista;
	double soma = 0;
	
	cout << "------------------------------------" << endl;
	
	while (aux != NULL) {
		cout    << "Prontuario: " << aux->dados->prontuario <<  endl 
		        << "Nome: "       << aux->dados->nome       <<  endl 
		        << "Salario: "    << aux->dados->salario    <<  endl;
		        
		cout << "------------------------------------" << endl;
		
		soma+=aux->dados->salario;     
		aux = aux->prox;
	}
	
	cout << "------------------------------------" << endl;
	if(lista != NULL){
	    cout << "Total dos salarios: " << soma << endl;
	}else{
	    cout << "Total dos salarios: 0" << endl;
	}
	
	cout << "------------------------------------" << endl;

}

// pesquisar:

Lista* find(Lista* lista, int prt) {
    Lista* aux;
	aux = lista;
	
	cout << "------------------------------------" << endl;
	
	while (aux != NULL && aux->dados->prontuario != prt) {
		aux = aux->prox;
	}	
	return aux;
}

// excluir:
Lista* remove(Lista* lista, int i) {
    Lista* aux;
    Lista* ant = NULL;
    
	aux = lista;
	
	cout << "------------------------------------" << endl;
	
	while (aux != NULL && aux->dados->prontuario != i) {
	    ant = aux;	
		aux = aux->prox;
	}
	
	if (aux == NULL) { // não estava
		return lista;
	}	
	
	if (ant == NULL) { // era o primeiro
		lista = aux->prox;
	}
	else { // estava no meio
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

void freeLista(Lista* lista) {
    Lista* aux;
	aux = lista;
	while (aux != NULL) {
		Lista *ant = aux->prox;
		free(aux);
		aux = ant;
	}	
}


void opAcao(Lista *listaFuncionario){
    int op;
    
    int prontuario;
    string nome;
    double salario;
    
    Lista *pesquisa;
    
    //cout << "------------------------------------" << endl;
    cout << "Escolha sua opcao: " << endl
         << "0. Sair"             << endl
         << "1. Incluir"          << endl
         << "2. Excluir"          << endl
         << "3. Pesquisar"        << endl
         << "4. Listar"           << endl;
         
    cin >> op;
    
    while(op != 0){
        switch(op){
        
            case 1:
            
                cout << "------------------------------------" << endl;
                
                cout << "Prontuario: "; 
                cin >> prontuario;
                cin.ignore();
                    
                cout << endl << "Nome: ";
                getline(cin, nome);
                   
                cout << endl << "Salario: ";
                cin >> salario;
                
                cout << endl;

                // implementar condicao de existencia
                
                pesquisa = find(listaFuncionario, prontuario);
                if (pesquisa != NULL) {
            		cout << "O usuario " << pesquisa->dados->prontuario << " ja existe!" << endl;
            	}else{
            	
                    listaFuncionario = insert(listaFuncionario, 
                                              prontuario, 
                                              nome, 
                                              salario);
            	}
            	
                break;
            case 2:
                // paramaters
                cout << "------------------------------------" << endl;
                
                cout << "Insira o usuario (prontuario) que deseja excluir: " << endl;
                cin >> prontuario;
                
                pesquisa = find(listaFuncionario, prontuario);
                if (pesquisa == NULL) {
                    cout << "O usuario informado nao existe!" << endl;
                }
                else{
                    listaFuncionario = remove(listaFuncionario, prontuario);    
                }
                
                print(listaFuncionario);
                
                break;
            
            case 3:
                // paramaters
                
                cout << "Pesquisar por prontuario: " << endl;
                cin >> prontuario;
                
                pesquisa = find(listaFuncionario, prontuario);
                if (pesquisa != NULL) {
            		cout << "Nome: "       << pesquisa->dados->nome       << endl
            		     << "Prontuario: " << pesquisa->dados->prontuario << endl
            		     << "Salario: "    << pesquisa->dados->salario    << endl;
            		     
            		     cout << "------------------------------------" << endl;
            	}
            	else {
            		cout << "Não encontrado" << endl;
            		
            		cout << "------------------------------------" << endl;
            	}
            	
                break;
                
            
            case 4:
                // paramaters
                print(listaFuncionario);
                break;
            
            default:
                freeLista(listaFuncionario);
                break;

        }
        
        op = 0;
        opAcao(listaFuncionario);
    }     
    
}


int main(int argc, char** argv)
{
    
    Lista *minhaLista;
    minhaLista = init();
    
    opAcao(minhaLista);
    
    freeLista(minhaLista); // caso a opcao 0 seja a primeira opcao selecionada
    return 0;
}




