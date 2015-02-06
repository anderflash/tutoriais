#include <gtk/gtk.h>
#include <stdio.h> // Para o printf

botao_clicked_cb(GtkButton* button, gpointer user_data)
{
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
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// Criar o botão
	button = gtk_button_new_with_label("Botão");

	// Obter o evento do botão
	g_signal_connect(button, "clicked", G_CALLBACK(botao_clicked_cb), NULL);

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