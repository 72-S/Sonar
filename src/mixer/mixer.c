#include "../include/mixer/mixer.h"
#include "src/mixer/mixer_ui.h"
#include <gtk/gtk.h>

void mixer_activate(GtkApplication *app) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Sonar Volume Mixer");
  gtk_window_set_modal(GTK_WINDOW(window), TRUE);
  gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 400);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_window_set_transient_for(GTK_WINDOW(window), NULL);

  build_ui(window);

  gtk_widget_set_visible(window, TRUE);

  g_print("Mixer Window\n");
}
