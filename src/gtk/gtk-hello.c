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
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	// Indicar que deve ser mostrado
	gtk_widget_show(window);

	// Mostrar os controles de fato e fique executando 
	// (não termine o programa imediatamente)
	gtk_main();

	return 0;
}