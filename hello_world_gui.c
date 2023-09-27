#include <gtk/gtk.h>
#define WINDOW_SIZE 200

// Keep counts of the number of times the click me now button is pressed
static int COUNT = 0;

// Declare the fuction variable
// Welcome message when the button is clicked
void welcome(GtkWidget*, gpointer);

// Destroy by quiting the button
void destroy(GtkWidget*, gpointer);

// The window widget
int main(int argc, char* argv[]){
	GtkWidget* window;
	GtkWidget* button;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), WINDOW_SIZE);

	// Create the button	
	button = gtk_button_new_with_label("Click Me Now!");

	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(welcome), "button");
	
	// Add the gtk container with its button
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

// Welcome message 
void welcome(GtkWidget* widget, gpointer data){
	// printf equivalent in GTK+
	g_print("Hello World!\n");
	g_print("%s Clicked %d times\n", (char*)data, ++COUNT);
}

// To destroy the widget
void destroy(GtkWidget* widget, gpointer data){
	gtk_main_quit();
}
