#include "mixer_ui.h"
#include "gtk/gtk.h"

void build_ui(GtkWidget *window) {
    // Create a container for widgets
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Add widgets to the container
    GtkWidget *label = gtk_label_new("TEST");
    gtk_box_append(GTK_BOX(box), label);


}
