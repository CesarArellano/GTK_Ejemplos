/* buttonsentry.c
   Este ejercicio muestra el uso de contenedores, botones y
   espacios de entrada con sus funciones de callback y seniales

*/

#include <gtk/gtk.h>
#include <string.h>


GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ButtonClicked(GtkButton *button, gpointer data);
void StopTheApp(GtkWidget *window, gpointer data);
void HelloAction(GtkButton *button, gpointer data);
void Imprimir(GtkButton *button, gpointer data);


gint main ( gint argc, gchar *argv[])
{

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;
  GtkWidget *verticalbox;
  GtkWidget *entrybox;
  GtkWidget *otracaja;
  

  gtk_init(&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),320,200);
  gtk_container_border_width(GTK_CONTAINER(window),7);

  
  verticalbox = gtk_vbox_new(TRUE,5);

  entrybox = gtk_entry_new();
  
  box = gtk_hbox_new(TRUE,5);
  otracaja = gtk_hbox_new(TRUE,5);
  
  button = AddButton(box,"pon texto",ButtonClicked,entrybox);
  button = AddButton(box,"captura texto",HelloAction,entrybox);
  button = AddButton(otracaja,"Imprimir en Terminal",Imprimir,entrybox);

  /*  //boton 1
  button = gtk_button_new_with_label("Pon Texto"); // Podemos reutilizar variables para crear más items, ya que el mostrarlo, ya está creado.
  gtk_box_pack_start(GTK_BOX(box),button,TRUE,TRUE,5); //Empaqueta a la caja horizontal
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox); // Conecta la señal con la funcion a ejecutar
  gtk_widget_show(button); // Muestra el boton

  //boton 2
  
  button = gtk_button_new_with_label("Captura Texto"); 
  gtk_box_pack_start(GTK_BOX(box),button,TRUE,TRUE,5);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(HelloAction),entrybox);
  gtk_widget_show(button);

  //boton 3
  button = gtk_button_new_with_label("Captura Texto"); 
  gtk_box_pack_start(GTK_BOX(otracaja),button,TRUE,TRUE,5);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(HelloAction),entrybox);
  gtk_widget_show(button);
  
  */
  
  gtk_box_pack_start(GTK_BOX(verticalbox),entrybox,TRUE,TRUE,0); // Empaqueto en la caja principal / vertical la entrada de texto.
  gtk_box_pack_start(GTK_BOX(verticalbox),box,TRUE,TRUE,0); // Empaqueto en la caja principal / vertical los botones.
  gtk_box_pack_start(GTK_BOX(verticalbox),otracaja,TRUE,TRUE,0); 
  
  
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);
  

  gtk_container_add(GTK_CONTAINER(window),verticalbox);
  
  gtk_widget_show_all(window);
  
  gtk_main();

  return 0;

}



GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
    gtk_widget_show(button);
    return button;
    

}


void ButtonClicked(GtkButton *button, gpointer data)
{
    g_print("Button got clicked \n");
    gtk_entry_set_text(GTK_ENTRY(data),"Hola Mundo");
    
    

}



void HelloAction(GtkButton *button, gpointer data)
{
    const gchar *text;
    
    
    text =gtk_entry_get_text(GTK_ENTRY(data));
    
    g_print("%s",text);
    
    

}

void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    

}

void Imprimir(GtkButton  *button, gpointer data)
{
 g_print("JAJAJAJAJAJA"); 
}
