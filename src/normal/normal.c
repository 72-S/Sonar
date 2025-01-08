#include "../include/normal/normal.h"
#include <gtk/gtk.h>

void normal_activate(GtkApplication *app) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Sonar");
  gtk_widget_set_visible(window, TRUE);

  g_print("Main Window\n");
}

