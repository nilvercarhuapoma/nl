#include <stdio.h>
#include <gtk/gtk.h>

int main (int argc, char **argv)
{
  printf ("hello world\n");


  gtk_init (&argc, &argv);


  GtkDialog *dialog = GTK_DIALOG (gtk_message_dialog_new
    (NULL,
     GTK_DIALOG_DESTROY_WITH_PARENT,
     GTK_MESSAGE_ERROR,
     GTK_BUTTONS_CLOSE,
     "Hello, world"));

  gtk_dialog_run (dialog);

  gtk_widget_destroy (GTK_WIDGET (dialog));
}