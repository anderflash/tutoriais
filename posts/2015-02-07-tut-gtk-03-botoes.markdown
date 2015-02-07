---
title: Tutorial GTK+: 03-Botões
anterior: 2015-02-05-tut-gtk-02-introducao
posterior: 2015-02-05-tut-gtk-04-layouts
author: Anderson Tavares
---
<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-06-tut-gtk-02-helloworld.html">02-Hello World
  </a></span><span class="linkdireito"><a href=
    "2015-02-08-tut-gtk-04-layouts.html">04-Layouts
</a></span>
</div>
![](../images/gtk-button.png)

Oi, pessoal. Neste tutorial iniciaremos nossas atividades com os controles. Um conceito precisa ser explicado nessa jornada. Os componentes contém outros componentes, formando uma árvore estruturada. A esse padrão, damos o nome de [Composite![](../images/externallink.png)](http://pt.wikipedia.org/wiki/Composite). Esse nome não é específico de GTK, mas de uma área denominado [Design Patterns![](../images/externallink.png)](http://pt.wikipedia.org/wiki/Padr%C3%A3o_de_projeto_de_software), que nasceu com a necessidade de catalogar estruturas e relações entre objetos que aparecem com bastante frequência nas aplicações, com vantagens e desvantagens.

A janela será um _Composite_ que conterá um botão como componente filho. 

``` c
// gtk-button.c
#include <gtk/gtk.h>
#include <stdio.h> // Para o printf

botao_clicked_cb(GtkButton* button, gpointer user_data)
{pandoc underlined
	printf("Hello World\n");
}

int main(int argc, char** argv)
{
	// Declarar os componentes
	GtkWidget* window;
	GtkWidget* button; // Variável para o botão
	
	// Inicializar GTK+
	gtk_init(&argc, &argv);

	// Definir os componentes
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	// EVENTO: Fechar a janela => Fechar o programa
	g_signal_connect(window, "destroy",
	                 G_CALLBACK(gtk_main_quit), NULL);

	// Criar o botão
	button = gtk_button_new_with_label("Botão");

	// Obter o evento do botão
	g_signal_connect(button, "clicked",
	                 G_CALLBACK(botao_clicked_cb), NULL);

	// Associá-lo à janela e mostrá-lo
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show(button);
	
	// Indicar que deve ser mostrado
	gtk_widget_show(window);

	// Mostrar os controles de fato e fique executando 
	// (não termine o programa imediatamente)
	gtk_main();

	return 0;
}
```
## Compilando

```bash
gcc gtk-button.c -o gtk-button `pkg-config --libs --cflags gtk+-3.0`
```

Na primeira figura, ao clicar no botão, um `Hello World` é mostrado no console (melhor executar através do console ao invés do duplo-clique sobre o programa).

## Explicando

Adicionei a biblioteca `stdio.h` para executar a função `printf`. Depois criei a função que será executada toda vez que o botão for pressionado. Uma convenção para o GTK é nomear a função com o evento e um sufixo `_cb` (de *callback*).

A função recebe o objeto que emitiu o sinal e um ponteiro para os dados (`gpointer` do `GLib`). Por enquanto estamos enviando `NULL`.

Depois de escrever o código semelhante ao [tutorial anterior](2015-02-05-tut-gtk-02-helloworld.html) (inicializar o gtk, criar a janela, associar os eventos da janela e iniciar o laço), criamos o botão (`gtk_button_new_with_label`), associamos o evento `clicked` para executar a função `botao_clicked_cb`, e inseriu na janela (`gtk_container_add`). O padrão _Composite_ é implementado em GTK com o tipo `GtkContainer`.

Mesmo adicionado à janela, o botão não será mostrado. Por isso a função `gtk_widget_show` é executada para o botão. Outra forma é trocar

``` c
gtk_widget_show(window);
```

por 

``` c
gtk_widget_show_all(window);
```

Mostrando a janela e todos os seus filhos. Todavia nem sempre você quererá exibir todos os componentes associados.

## Exercícios

1. Crie uma janela com um botão que, ao ser clicado, feche a aplicação. Lembra do `gtk_main_quit`?
2. Crie uma janela com um botão que não pode ser clicado (inativo). Dica: [`gtk_widget_set_sensitive`](https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-sensitive)
3. Crie uma janela com um botão que contenha o ícone padrão "gtk-add" ao invés de um texto. Dica: [`gtk_button_new_from_icon_name`](https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-new-from-icon-name)
4. Crie uma janela com um botão que, ao clicar, imprima no console seu label ([`gtk_button_get_label`](https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-get-label))


## Observações

Ao estudar este tipo de exemplo, ainda nos deparamos com uma dúvida: e esse `gpointer`? Talvez esteja na hora de aprender um pouco a biblioteca [GLib](../tut/tut-glib.html), senão, à medida que for avançando nos tutoriais GTK+, mais dúvidas não respondidas podem aparecer.

<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-06-tut-gtk-02-helloworld.html">02-Hello World
  </a></span><span class="linkdireito"><a href=
    "2015-02-08-tut-gtk-04-layouts.html">04-Layouts
</a></span><span class="linkcentral"><a href=
    "#">Topo
</a></span>
</div>