---
title: Tutorial GTK+: 01-Introdução
author: Anderson
---

<div class="tutlinks"><span class="linkdireito"><a href=
    "2015-02-06-tut-gtk-02-helloworld.html">02-Hello World
</a></span>
</div>

![](../images/gtk-introducao2.png)

Olá pessoal, este é meu primeiro tutorial sobre GTK+. Todo o código estará disponível no [github](http://www.github.com/anderflash/tutorialgtkglibgobject).

Inicialmente trabalharemos com 3 tipos de componentes:

- *Janelas*: área visual contendo e agrupando outros componentes gráficos de uma aplicação.
- *Controles*: componentes visuais para interação com o usuário
- *Layouts*: elementos que organizam os controles nas janelas.



Mas por que existem estes tipos de componentes? Por que foi organizado deste jeito?

A [Wikipedia](http://en.wikipedia.org/wiki/History_of_the_graphical_user_interface) traz informações interessantes sobre a evolução da interface gráfica de usuário e pode dar uma visão geral da necessidade destes componentes.

## Instalação

Em plataformas GNU/Linux, é necessário instalar o pacote GTK+, dessa maneira:

``` bash
sudo pacman -S gtk3 # Arch Linux
sudo apt-get install libgtk-3-dev # Ubuntu
yum install gtk3-devel # Fedora
```

A [página oficial do GTK![](../images/externallink.png)](http://www.gtk.org/download/index.php) contém informações para instalações também no Mac e no Windows.

## Compilação

Para compilar os programas, basta escrever:

```bash
gcc [ARQUIVOS] -o [PROGRAMA] `pkg-config --cflags --libs gtk+-3.0`
```


O próximo tutorial mostrará como instalar as bibliotecas. Caso você já esteja seguro de que as bibliotecas já estão instaladas, você pode partir para o [Hello World]().

<div class="tutlinks"><span class="linkdireito"><a href=
    "2015-02-06-tut-gtk-02-helloworld.html">02-Hello World
</a></span>
</div>