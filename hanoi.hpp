typedef struct inf_no{ /// Informa��es de dentro da pilha
    int valortraco;
    string traco;

}Inf_no;

typedef struct bloco{ /// Bloco de pilha (n�)
    Inf_no info;
    bloco *prox;

}Bloco;

typedef struct pilhadehanoi{ /// Topo da pilha (ref)
    Bloco *topo;

}Pilha;

int Pilha_Contador;

void inic(Pilha *p){ /// Inicializa a pilha
    p->topo = NULL;
    Pilha_Contador = 0;
}

bool isEmpty(Pilha *p){ ///Verifica se a pilha est� vazia
    if(p->topo == NULL)
        return true;
    else
        return false;
}

bool pushdehanoistart(Pilha *p, Inf_no info){  ///empilhar
        Bloco *novo = new Bloco();

        if(!novo)   ///sistema operacional n�o conseguiu alocar a mem�ria
            return false;

        novo->info = info;
        novo->prox = p->topo;
        p->topo = novo;
        return true;

}

bool pushdehanoi(Pilha *p, Inf_no info){  ///empilhar
        Bloco *novo = new Bloco();

        if(!novo)   ///sistema operacional n�o conseguiu alocar a mem�ria
            return false;

        novo->info = info;
        novo->prox = p->topo;
        p->topo = novo;
        Pilha_Contador++;
        return true;

}

bool popdehanoi(Pilha *p, Inf_no *info){  ///desempilhar
    if(isEmpty(p))
        return false;

    *info = p->topo->info;    ///(*p).(*topo).reg
    Bloco *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;
    return true;
}

bool verifyhanoi(Pilha *pstart, Pilha *pend, Inf_no *info){
    Bloco *blocostart = pstart->topo;
    Bloco *blocoend = pend->topo;

    if(isEmpty(pend) || blocostart->info.valortraco < blocoend->info.valortraco)
        return true;
    else
        return false;
}
bool transferdehanoi(Pilha *pstart, Pilha *pend, Inf_no *info){
    if(isEmpty(pstart))
        return false;

    Inf_no info1 = pstart->topo->info;

    if(verifyhanoi(&*pstart, &*pend, &*info)){
        pushdehanoi(pend, info1);
        popdehanoi(pstart, &info1);

        return true;

    }else{
        return false;
    }
}

void showdehanoi(Pilha *p){
    Bloco *bloco = p->topo;

    for(int i = 0; i < 5; i++)
        cout << "\t\t\t" << "|" << "\t\t\t" << endl;

    while(bloco != NULL){
        cout << "\t\t  " << bloco->info.traco << "\t\t\t" << endl;
        bloco = bloco->prox;
    }

    cout << endl;

}

void apagardehanoi(Pilha *p){
    Bloco *apagar;
    Bloco *pos = p->topo;

    while(pos != NULL){
        apagar = pos;
        pos = pos->prox;
        delete apagar;
    }
    p->topo = NULL;
}

void resetdehanoi(Pilha *p, Pilha *p2, Pilha *p3){
    apagardehanoi(p);
    apagardehanoi(p2);
    apagardehanoi(p3);
    cout << "STACKS ERASED." << endl;
}

int ganhouhanoi(Pilha *p){
    Bloco *bloco = p->topo;
    int cont = 0;
    while(bloco != NULL){
        cont++;
        bloco = bloco->prox;

    }

    return cont;

}
