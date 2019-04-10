#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data) //Cada conexion a señales tiene este encabezado.
{
  g_print("Hola Perro Mundo \n");
}


void destroy(GtkWidget *widget, gpointer data)
{
  gtk_main_quit(); // Cierra el proceso.
}

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;


  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Indica que la variable window es Ventana Principal

  gtk_signal_connect(GTK_OBJECT(window),"destroy", GTK_SIGNAL_FUNC(destroy), NULL); // Cierra el proceso de la aplicación

  gtk_container_set_border_width(GTK_CONTAINER(window),10); // Le agrega un contenedor con diferencia de 10 pixeles a window

  button=gtk_button_new_with_label("Hola Mundo"); // Crea el boton con la etiqueta Hola Mundo
 
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(hello), NULL); // Conectamos la señal al boton, "clicked" -> debe llamarse como al documentación.

  gtk_container_add(GTK_CONTAINER(window),button); // El boton le añadimos el button a la ventana.

  gtk_widget_show(button); // Muestra en pantalla el boton.
  gtk_widget_show(window); // Muestra en pantalla la ventana.


  gtk_main(); // Inicia un loop infinito para la ejecucion de la aplicacion.

  return(0);
}
