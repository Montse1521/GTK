#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data) {
    g_print("Montserrath Galvan Velazquez\n");
}

// Función de callback para el evento de eliminación
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    g_print("delete event occurred\n");
    return TRUE;
}

void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Crear ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Configurar la señal "delete_event" para la ventana
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);

    // Configura la señal "destroy" para la ventana
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

    gtk_container_set_border_width (GTK_CONTAINER(window), 10);

    button = gtk_button_new_with_label("Montserrath Galvan Velazquez");

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(hello), NULL);

    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show(button);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}
