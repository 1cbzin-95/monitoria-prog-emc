char nomeLogado[21];
#define ENTER  0x0D
typedef struct cadastrados{
		char login[21];
		char email[41];
		char senha[21];
		struct cadastrados *prox;
}uSuario;
//-----------------------------------------PARTE RELACIONADA AOS LOGUIN E USUARIOS
int menuadmin(void);
int loginAdm(uSuario *fichaDuSEr);
int menuUser(void);
void chamaFuncADMin(Relat *fichario,Ficha *lista,uSuario *fichaDuSEr);
void chamaFuncUser(Relat *fichario,Ficha *lista,uSuario *fichaDuSEr);
uSuario *dUeserVazio(void);
void preenUser(uSuario **fichaDuSEr);
void leer_User(uSuario *fichaDuSEr);
void lerAqui(uSuario **fichaDuSEr);
void gravar(uSuario **fichaDuSEr);
void atualizarArqui(void);
void libedUeser(uSuario *fichaDuSEr);
