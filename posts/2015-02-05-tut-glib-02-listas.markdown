---
title: Tutorial GLib: 02-Listas
author: Anderson Tavares
---

Oi, pessoal. Neste tutorial aprenderemos sobre listas. Antes disso preciso mostrar alguns problemas para entendermos porque foi inventado esse tipo de estrutura.

## Cenário 1: Inimigos em um Jogo de Tiro de Primeira Pessoa

Digamos que estejas criando um jogo e precisa criar inimigos. Embora tenha ordem na criação, o problema é quando o jogador mata um inimigo. Se você estiver utilizando um vetor, olha o que acontece quando você tenta remover o inimigo morto do vetor:

![](glib-listas-inimigos1.png)

Você precisa mover todos os inimigos à direita de forma que o espaço vazio se junte ao final. Se o inimigo morto estiver no início, você precisa mover praticamente todos os inimigos vivos para a esquerda. 

Nesse pior caso, tendo N inimigos, o algoritmo para remover um inimigo morto é de complexidade O(N). Imagina só se o teu jogo contém milhões de inimigos!!!

Será que existe uma forma de que a remoção de um elemento dentro de um grupo tenha complexidade O(1)?

## Cenário 2: Cartas de Baralho

Imagina uma competição com vários jogadores segurando um grupo de cartas. Se você representar as cartas como elementos em um vetor, qualquer remoção deixa "espaços vazios" no grupo. Tudo bem que geralmente uma pessoa contém geralmente até 10 cartas na mão, mas e se tua aplicação estiver na Web e milhões de jogadores estiverem realizando esta operação?

![](glib-listas-cartas.png)

## Cenário 3: Filas de Banco com Prioridades

Digamos que a fila neste banco seja uma fila única, porém algumas pessoas são mais prioritárias. Digamos que tenha um organizador da fila. Quando ele percebe que uma pessoa precisa ser inserida na fila numa posição que não seja o final, se a fila for implementada como um vetor, todas as pessoas de trás precisariam ser movidas para trás para oferecer um espaço vazio para a nova pessoa com prioridade.

Será que há uma forma de inserir um elemento na fila sem precisar mover todo mundo para obter um espaço na posição desejada?

![](glib-listas-filas.png)

## Cenário 4: Compra de passagens em avião

Digamos que não sabemos quantos passageiros comprarão passagens para tal avião. Mesmo sabendo que os aviões contém números fixos de assentos, alocar espaço na memória para todos os assentos de todos os aviões para o sistema da Infraero seria um desperdício. 

Fixemos no vetor. Então o vetor inicialmente estaria desalocado. Quando o primeiro passageiro faz uma compra, o vetor será alocado. O problema ocorre quando o segundo passageiro faz a compra. O vetor não é redimensionável. Nesse caso, é criado um novo vetor maior do que o anterior, e o conteúdo do primeiro vetor é copiado para o novo vetor. Fazendo isso sempre causa um desperdício de processamento e memória quando um grande número de elementos precisam ser copiados de um vetor para outro apenas para acomodar um novo passageiro.

Existe uma forma de acomodar um novo passageiro e não criar um novo grupo toda vez que isso acontecer?

## Debate sobre os problemas

Existem outras situações que contém problemas similares. Além disso, vimos apenas problemas com vetores para motivar a necessidade. Isso por que ainda não vimos as outras estruturas para comparação. Todavia, basicamente dois problemas ocorrem nestes cenários:

- Inserção de elementos no vetor é O(N)
- Remoção de elementos no vetor é O(N)

## Listas

Listas são estruturas que permitem adicionar e remover itens em qualquer posição com complexidade O(1). 

Se você desejar criar sua própria implementação de lista, provavelmente você iniciará com essa estrutura:

``` c
struct Lista
{
	int dado;
	struct Lista* proximo;

	// Para listas duplamente vinculadas
	struct Lista* anterior; 
};

```

A GLib oferece uma estrutura `GSList` para listas simplesmente encadeadas, e `GList` para duplamente encadeadas.

O código abaixo mostrará um simples exemplo de uso da `GList`:

``` c
int main(int argc, char** argv)
{
	GSList* list = 
}
```

## Listas Circulares

- Multiplexação no tempo em telefonia celular


## Exercícios

1. Faça
2. Faça