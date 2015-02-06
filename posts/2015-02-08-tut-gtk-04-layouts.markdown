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

Oi, pessoal. Neste tutorial fftrabalharemos com a inserção e organização de mais de um controle utilizando layouts, formando janelas mais complexas.

Muitas vezes você pode pensar: mas é só colocar o controle na posição desejada. Porém, o programador pode querer apenas adicionar o controle, e que a própria interface se encarregue de posicioná-lo de forma conveniente.

Outro problema ocorre ao redimensionar a janela. O que acontece? O espaço adicional (se a janela for ampliada) fará algum controle também se redimensionar? A esta capacidade, denominamo-lo como *interface líquida*, uma interface capaz de se adaptar a diferentes dispositivos e tamanhos. É uma propriedade interessante de se adquirir.

Várias maneiras de ajudar na organização dos controles foi criada para auxiliar o desenvolvedor nesta tarefa. Antes do tecniquês, vamos tentar imaginar situações que justificassem esses layouts:

- Botões adicionados um ao lado do outro (ex: salvar, cancelar, novo...). Se um novo botão for adicionado, que ele fique ao lado do último botão, sem precisar dizer explicitamente a posição dele.
- Formulário para cadastrar uma nova pessoa, onde os rótulos ficam na esquerda, alinhados à direita entre si, e os controles de entrada (caixas de texto, radioboxes, checkboxes), na direita, alinhados à esquerda.
- Alinhamento e espaçamento dos controles de forma precisa, para agrupar controles, facilitando sua visualização.
- Listas que expandem seu tamanho, aproveitando o espaço para visualizar mais itens.
- Em alguns editores de texto, há o explorador de arquivos, um painel mostrando a árvore de pastas e arquivos. Geralmente ela é redimensionável, para visualizar pastas de profundidades grandes, ou para acomodar mais espaço para o texto no painel central do editor.
- ... infinitos outros cenários.

``` c
int main(int argc, char** argv)
{
	return 0;
}
```

<div class="tutlinks">
  <span class="linkesquerdo"><a href=
    "2015-02-07-tut-gtk-03-botoes.html">03-Botões
  </a></span><span class="linkdireito"><a href=
    "2015-02-09-tut-gtk-05-aplicacoes.html">05-Aplicações
</a></span><span class="linkcentral"><a href=
    "#">Topo
</a></span>
</div>