typedef struct deposito{
	char nome[31];
	long int iD;
	int quantidade;
	int dia,mes,ano;//data automatica
	int vencidia,vencimes,venciano;//data manual "de vencimento"
	struct deposito *prox;
}Ficha;
//-----------------------------------------TODA A PARTE RELACIONADA  AO ESTOQUE GERAL
typedef struct relatorio{
	char loginUsado[21];
	int oprealizada;
	long int iDprod;
	int quantidade;
	int dia,mes,ano;
	struct relatorio *prox;
}Relat;
//-----------------------------------------PARTE RELACIONADA AO RELATORIO DE ESTOQUE
Ficha *listaVazia(void);
Ficha *preencherLista(Ficha *lista);
void lerLista(Ficha *lista);
int tamanhoLista(Ficha *lista);
int removerElemento(Ficha **lista,long int identificador);
void liberarLista(Ficha *lista);
void gravarArquivo(Ficha *lista);
void lerArquivo(Ficha **lista);
void atualizaArquivo(void);
void buscarProduto(Ficha *lista,long int identificador);
int qualAlterar(void);
int alterarElem(Ficha **lista,long int identificador);
int verificaID(Ficha *lista,long int id);
void VerProdVencimento(Ficha *lista);

Relat *ficharioVazio(void);
void libefichario(Relat *fichario);
void verRelatorio(Relat *fichario);
void lerRelatorio(Relat **fichario);
void gravarRela(Relat **fichario);
void atuaizarRela(void);
int acrescNoProduto(Ficha **lista,long int identificador,Relat **fichario);
int retirarNoProduto(Ficha **lista,long int identificador,Relat **fichario);
void verporData(Relat *fichario);//##
