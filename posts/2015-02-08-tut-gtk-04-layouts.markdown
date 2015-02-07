---
title: Tutorial GTK+: 04-Layouts
author: Anderson Tavares
---

<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-07-tut-gtk-03-botoes.html">03-Botões
  </a></span><span class="linkdireito"><a href=
    "2015-02-09-tut-gtk-05-aplicacoes.html">05-Aplicações
</a></span>
</div>

<span style="vertical-align:top;">![](../images/gtk-layouts-3.png)</span>![](../images/gtk-layouts-5.png)
<div style="text-align:center;">![](../images/gtk-layouts-4.png)</div>

Oi, pessoal. Neste tutorial trabalharemos com a inserção e organização de mais de um controle utilizando layouts, formando janelas mais complexas. São vários layouts, talvez você queira não aprender todos de uma vez. De qualquer forma, o tutorial estará disponível para você voltar e aprender mais um pouco.

Muitas vezes você pode pensar: mas é só colocar o controle na posição desejada. Porém, o programador pode querer apenas adicionar o controle, e que a própria interface se encarregue de posicioná-lo de forma conveniente.

Outro problema ocorre ao redimensionar a janela. O que acontece? O espaço adicional (se a janela for ampliada) fará algum controle também se redimensionar? A esta capacidade, denominamo-lo como *interface líquida*, uma interface capaz de se adaptar a diferentes dispositivos e tamanhos. É uma propriedade interessante de se adquirir.

Várias maneiras de ajudar na organização dos controles foi criada para auxiliar o desenvolvedor nesta tarefa. Antes do tecniquês, vamos tentar imaginar situações que justificassem esses layouts:

- Botões adicionados um ao lado do outro (ex: salvar, cancelar, novo...). Se um novo botão for adicionado, que ele fique ao lado do último botão, sem precisar dizer explicitamente a posição dele.
- Formulário para cadastrar uma nova pessoa, onde os rótulos ficam na esquerda, alinhados à direita entre si, e os controles de entrada (caixas de texto, radioboxes, checkboxes), na direita, alinhados à esquerda.
- Alinhamento e espaçamento dos controles de forma precisa, para agrupar controles, facilitando sua visualização.
- Listas que expandem seu tamanho, aproveitando o espaço para visualizar mais itens.
- Em alguns editores de texto, há o explorador de arquivos, um painel mostrando a árvore de pastas e arquivos. Geralmente ela é redimensionável, para visualizar pastas de profundidades grandes, ou para acomodar mais espaço para o texto no painel central do editor.
- ... infinitos outros cenários.

## Box

O Box é um *container* que dispõe os controles filhos em uma fileira (linha ou coluna). Você pode colocar outros *containers* dentro de um box. Dessa forma, você pode dividir a organização de uma janela. Geralmente o box pode ser usado para dividir seções principais de uma janela (ex: cabeçalho, principal e status).

O box é criado usando a função 

``` c
GtkWidget* gtk_box_new(GtkOrientation orientacao, gint espacamento);
```

onde a orientação pode ser `GKT_ORIENTATION_HORIZONTAL` ou `GKT_ORIENTATION_VERTICAL`, e o espaçamento é o número de pixels entre os controles da caixa.

Adicionar os controles na caixa é feito usando

``` c
void
gtk_box_pack_start (GtkBox *box,
                    GtkWidget *child,
                    gboolean expand,
                    gboolean fill,
                    guint padding);
```

ou

``` c
void
gtk_box_pack_end   (GtkBox *box,
                    GtkWidget *child,
                    gboolean expand,
                    gboolean fill,
                    guint padding);
```

Onde o controle é adicionando a partir do topo (`start`) ou da base (`end`). Geralmente iremos usar o `start`. Um exemplo de usar o `end` é a barra de status, que mesmo redimensionando a janela, a barra fica presa na base da janela.

Se `expand` é `TRUE`, então a nova célula da caixa que acomodará o controle receberá o espaço adicional. Se duas ou mais células da caixa ativarem esta opção, o espaço adicional será dividido igualmente entre eles.

Se `fill` é `TRUE`, então de fato o espaço que a célula recebeu vai para o controle, ao invés de ser um espaço vazio. Veja que `fill` só faz sentido se `expand` for `TRUE`.

O próximo exemplo mostrará dois botões dispostos horizontalmente dentro da caixa.

![](../images/gtk-layouts-box-example.png)

``` c
#include <gtk/gtk.h>
#include <stdio.h>

void btnSalvar_clicked_cb(GtkButton* button, gpointer user_data)
{
	printf("btnSalvar_clicked_cb\n");
}

void btnCancelar_clicked_cb(GtkButton* button, gpointer user_data)
{
	printf("btnCancelar_clicked_cb\n");
}

int main(int argc, char** argv)
{
	// Variáveis
	GtkWidget *janela;
	GtkWidget *box;
	GtkWidget *btnSalvar;
	GtkWidget *btnCancelar;

	// Inicializar o GTK
	gtk_init(&argc, &argv);

	// Criar os componentes
	janela      = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	box         = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	btnSalvar   = gtk_button_new_from_icon_name("gtk-save", GTK_ICON_SIZE_BUTTON);
	btnCancelar = gtk_button_new_from_icon_name("gtk-cancel",GTK_ICON_SIZE_BUTTON);

	// Associar os componentes
	gtk_box_pack_start(GTK_BOX(box), btnSalvar, TRUE, TRUE,0);
	gtk_box_pack_start(GTK_BOX(box), btnCancelar, TRUE, TRUE,0);
	gtk_container_add (GTK_CONTAINER(janela), box);
	g_signal_connect  (janela, "destroy", 
	                   G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect  (btnSalvar, "clicked", 
	                   G_CALLBACK(btnSalvar_clicked_cb), NULL);
	g_signal_connect  (btnCancelar, "clicked", 
	                   G_CALLBACK(btnCancelar_clicked_cb), NULL);

	// Mostrar os componentes
	gtk_widget_show_all(janela);

	// Iniciar o laço
	gtk_main();

	return 0;
}
```

As duas primeiras funções `btnSalvar_clicked_cb` e `btnCancelar_clicked_cb` são executadas quando respectivamente os botões `btnSalvar` e `btnCancelar` são clicados. O processo dentro do `main` é o mesmo dos exemplos anteriores (iniciar o GTK, criar os componentes, associá-los, indicar visibilidade, e iniciar o laço para mostrar e monitorar eventos).

Um dos exercícios do tutorial dos botões foi a criação de botões com ícones. Este é um exemplo.

## Grade (Grid)

## Fixo (Fixed)

## Caderno (Notebook)

## Moldura (Frame)

## Moldura Proporcional (AspectFrame)

## Caixa de Lista (ListBox)

## Revestir (Overlay)

## Barra de Menu (MenuBar)

## Barra de Ferramentas (Toolbar)

## Paleta de Ferramentas (ToolPalette)

## Envidraçado (Paned)

## Caixa de Botão (ButtonBox)

## Disposição (Layout)

## Caixa de Eventos (EventBox)

## Expansor (Expander)

## Porta de Visualização (Viewport)

## Janela de Rolagem (ScrolledWindow)

## Alinhamento (Alignment)

## Revelador (Revealer)



<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-07-tut-gtk-03-botoes.html">03-Botões
  </a></span><span class="linkdireito"><a href=
    "2015-02-09-tut-gtk-05-aplicacoes.html">05-Aplicações
</a></span><span class="linkcentral"><a href=
    "#">Topo
</a></span>
</div>

