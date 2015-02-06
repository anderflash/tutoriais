---
title: Tutorial GLib: 01-Introdução
author: Anderson Tavares
---
[\[02-Listas\]](2015-02-05-tut-glib-02-listas.html)

Oi, pessoal. Neste tutorial faremos uma introdução sobre a biblioteca GLib. A biblioteca GLib contém elementos para estruturar dados, gerenciar processos e threads. 

Senti a necessidade de aprendê-la para obter alguma biblioteca em C que pudesse ajudar na compreensão da biblioteca GTK+. Depois percebi que ela poderia ser usada até em aplicações que não necessitassem de GTK+.

Existem outras bibliotecas que podem fazer o mesmo papel, como Boost, Poco e o próprio STL, embora elas trabalhem em C++. Mas como várias aplicações conhecidas são baseadas em GTK+, então você pode aproveitar o provável carregamento da biblioteca na memória para desenvolver aplicações que consomem poucos recursos.

A biblioteca GLib começou dentro da biblioteca GTK+, com o objetivo de encapsular funções não diretamente ligadas à interface gráfica. O ambiente GNOME utiliza a biblioteca.

Esta série de tutoriais ajudará a ter habilidades de criar aplicações eficientes e, ao mesmo tempo, com elementos facilmente estruturáveis.

Aprenderemos listas, filas, pilhas, árvores, tabelas *hash*, vetores e relações. Em nome da didática, os tutoriais tentarão seguir uma abordagem *top-down*, mostrando primeiro os problemas que enfrentamos no dia-a-dia, para entender a real necessidade, e facilitar a absorção do conteúdo. Muitas vezes tentamos aprender tantos conceitos que, se não soubermos usar, cai no esquecimento.

Outra coisa que o tutorial conterá são exercícios de aprendizado. Tentarei colocar exercícios para resolver problemas reais, desafiando vossas mentes.

A [Wikipedia![](../images/externallink.png)](http://en.wikipedia.org/wiki/GLib) contém um resumo interessante sobre a biblioteca, o que ela faz, sua posição na arquitetura de software da GTK e sua história.

## Prerequisitos

Suponho que você sabe o que é programação e já trabalhou com o básico de C, como ponteiros, *structs* e vetores. Vamos precisar destes conceitos para entender a necessidade das estruturas de dados.

## Instalação

Em plataformas GNU/Linux, é necessário instalar o pacote GLib, dessa maneira:

``` bash
sudo pacman -S glib2 # Arch Linux (já instalado por padrão)
sudo apt-get install libglib2.0-dev # Ubuntu
yum install glib* # Fedora
```

A [página oficial do GTK![](../images/externallink.png)](http://www.gtk.org/download/index.php) contém informações para instalações também no Mac e no Windows. Instalando GTK+ por completo, você obtém o GLib.

## Compilação

Para compilar os programas, basta escrever:

```bash
gcc [ARQUIVOS] -o [PROGRAMA] `pkg-config --cflags --libs glib-2.0`
```

Se estiver também usando GTK+, basta apenas `gtk+-3.0`.

[\[02-Listas\]](2015-02-05-tut-glib-02-listas.html)