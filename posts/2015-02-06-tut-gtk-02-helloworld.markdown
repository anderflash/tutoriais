---
title: Tutorial GTK+: 02-Hello World
author: Anderson Tavares
---

<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-05-tut-gtk-01-introducao.html">01-Introduçao
  </a></span><span class="linkdireito"><a href=
    "2015-02-07-tut-gtk-03-botoes.html">03-Botões
</a></span>
</div>
 

![](../images/gtk-hello.png)

Olá pessoal, vamos apresentar um exemplo simples de como exibir sua primeira janela.

``` c
// gtk-hello.c
#include <gtk/gtk.h>
int main(int argc, char** argv)
{
	// Declarar os componentes
	GtkWidget* window;
	
	// Inicializar GTK+
	gtk_init(&argc, &argv);

	// Definir os componentes
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	// EVENTO: Fechar a janela => Fechar o programa
	g_signal_connect(window, "destroy",
	                 G_CALLBACK(gtk_main_quit), NULL);
	
	// Indicar que deve ser mostrado
	gtk_widget_show(window);

	// Mostrar os controles de fato e fique executando 
	// (não termine o programa imediatamente)
	gtk_main();

	return 0;
}
```

Vamos por partes. De um modo geral, precisamos iniciar a biblioteca, criar os componentes, interligá-los entre si e o programa, e começar o laço que mostrará os componentes visíveis e escutará os eventos do usuário.

## Iniciar a biblioteca

Nesse exemplo, simplesmente passaremos os argumentos para o GTK+, usando `gtk_init(&argc, &argv);`. Veja que precisamos dos ponteiros para o número de argumentos e para o vetor de argumentos, este sendo um ponteiro triplo, já que:

- um ponteiro de vetor de strings =
- ponteiro de vetor de vetor de char = 
- ponteiro de vetor (char*) = 
- ponteiro de (char**) = 
- char\*\*\*

ufa!!!.

## Criar os componentes

Nosso único componente aqui é a janela. As janelas são objetos `GtkWindow`, porém estamos declarando como `GtkWidget`, uma classe mais abstrata. Nesse caso, estamos simulando o encapsulamento do conceito de Orientação a Objetos. Olha aí a biblioteca `GObject` entrando em ação. Os controles, layouts e as janelas derivam do `GtkWidget`.

## Monitorar Eventos

Bom, o computador não tem como adivinhar quando o usuário interagirá com a interface (se bem que aprendizagem de máquina e inteligência artificial estão aí para ajudar). Nesse caso, a interface precisa continuamente monitorar essa possível interação. Tal interação provoca um evento (sinal). Neste exemplo, estamos apenas interligando um evento: se o usuário fechar a janela (`destroy`), então termine o laço principal do Gtk (e como o laço é a última instrução do programa, então o programa será terminado). Fazemos isto usando a função `g_signal_connect()`. Note que não a função começa com `g_`, e não `gtk_`, pois é uma função do `GLib`, já que *evento* é um conceito externo à GUI.

O primeiro argumento é o componente que emitirá o sinal. Nesse caso a janela notificará o GLib de que foi destruída. O GLib executará a função de *callback* `gtk_main_quit`, uma função definida do GTK que finaliza o laço iniciado por `gtk_main()`. O quarto argumento é algum dado que deseja enviar à função de *callback*. Depois aprenderemos a construir nossas próprias funções de *callback* e enviar dados personalizados a elas.

## Indicar a visibilidade da janela

Precisamos indicar que a janela precisa ser mostrada ao usuário. Nesse caso simplesmente usamos `gtk_widget_show()`. Veja que a função se nomeia `gtk_widget_show` e não `gtk_window_show`, já que janelas, layouts e controles podem ser mostradas ou não.

## Iniciar o laço

Por fim iniciamos o laço usando `gtk_main()`. É interessante se perguntar: se o nome da função é `gtk_main`, então existem laços secundários, tipo um `gtk_alternative` ou `gtk_secondary`? Bom, isso será melhor respondido quando utilizarmos o poder multicore dos processadores.

## Compilar

Para compilar simplesmente digite:

``` bash
gcc gtk-hello.c -o gtk-hello `pkg-config --libs --clags gtk+-3.0`
```
`pkg-config` é um comando que auxilia a obter os diretórios dos cabeçalhos e bibliotecas dos pacotes. Se quisermos utilizar apenas funções `GLib`, substituiremos `gtk+-3.0` por `glib-2.0`, que é sua versão atual.

Para executar basta escrever:

``` bash
./gtk-hello
```

O resultado deve aparecer como na primeira figura (screenshot em Openbox/LXDE).

Muita coisa pode ser alterada, como por exemplo o título, o tamanho inicial, se é modal, se é redimensionável, etc.

## Exercícios

1. Crie uma janela com o título `Exercício GTK Hello World` ([`gtk_window_set_title`![](../images/externallink.png)](https://developer.gnome.org/gtk3/unstable/GtkWindow.html#gtk-window-set-title))
2. Crie uma janela com o tamanho 800x600 ([`gtk_window_set_default_size`![](../images/externallink.png)](https://developer.gnome.org/gtk3/unstable/GtkWindow.html#gtk-window-set-default-size))
3. Crie uma janela que não seja redimensionável ([`gtk_window_set_resizable`![](../images/externallink.png)](https://developer.gnome.org/gtk3/unstable/GtkWindow.html#gtk-window-set-resizable))
4. Crie uma janela que apareça centralizada ao ser executada ([`gtk_window_set_position(GTK_WIN_POS_CENTER)`![](../images/externallink.png)](https://developer.gnome.org/gtk3/unstable/GtkWindow.html#gtk-window-set-position)).

O código para o gtk-hello.c está [aqui](https://github.com/anderflash/tutoriais/tree/master/src/gtk/gtk-hello.c)

<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-05-tut-gtk-01-introducao.html">01-Introduçao
  </a></span><span class="linkdireito"><a href=
    "2015-02-07-tut-gtk-03-botoes.html">03-Botões
</a></span><span class="linkcentral"><a href=
    "#">Topo
</a></span>
</div>

