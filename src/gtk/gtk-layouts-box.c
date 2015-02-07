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