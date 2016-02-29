/*
// gtk.cpp for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Mon Apr 27 17:52:00 2015 Alexandre Vanhoutte
<<<<<<< HEAD:gtk.cpp
// Last update Wed May  6 17:03:56 2015 Alexandre Vanhoutte
=======
// Last update Tue May  5 14:27:52 2015 Alexandre Vanhoutte
>>>>>>> 43764f4aaeaa057414fbfc1f6c1e68de52ac6810:bonus/gtk.cpp
*/

#include	<iostream>
#include	<cstring>
#include	<stdlib.h>
#include	<math.h>
#include	<gtk/gtk.h>

typedef	struct	s_obj
{
  GtkWidget	*accept;
  GtkWidget	*label[6];
  GtkWidget	*entry[6];
  GtkWidget	*error;
  GtkWidget	*win;
  GtkWidget	*title;
  GtkWidget	*box;
  GtkWidget	*arg[6];
  GtkWidget	*answer[5];
  const gchar	*text[5];
}		t_obj;

int		check_argument(t_obj *obj, char *str)
{
  int		i;

  i = 0;
  for (i = 0; i < 4; i++) {
    if (std::strlen(str) == 0){
	gtk_label_set(GTK_LABEL(obj->error), "Fejl: Hver felter skal udfyldes");
	return (-1);
    }
  }
  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9') {
	gtk_label_set(GTK_LABEL(obj->error), "Fejl: Argumenterne skal være tal.");
	return (-1);
      }
      i++;
    }
  return (0);
}

void		calc(GtkWidget *button, gpointer data)
{
  t_obj		*obj;
  int		flag;
  static  int	i = 0;
  char		buf[500];
  static double	res = 0;
  static double	res1 = 0;
  static double	res2 = 0;
  static double devia = 0;
  static double devia0 = 0;
  static double res0 = 0;

  obj = (t_obj *)data;
  obj->text[4] = strdup(gtk_entry_get_text(GTK_ENTRY(obj->entry[0])));
  if (strcmp(obj->text[4], "ende") == 0)
    exit(0);
  flag = check_argument(obj, (char *)obj->text[4]);
  static double result = atof(obj->text[0]);
  if (flag == 0)
    {
      result++;
      gtk_label_set(GTK_LABEL(obj->error), "");
      sprintf(buf, "%.2f", result);
      gtk_label_set(GTK_LABEL(obj->answer[0]), buf);

      /* devia */
      if (i == 0)
	{
	  devia = atof(obj->text[3]);
	  devia = sqrt((((((pow(devia, 2) + pow(atof(obj->text[1]), 2))) * (result - 1.0)) + pow(atof(obj->text[4]), 2)) / result) - pow((((atof(obj->text[1]) * (result - 1.0)) + atof(obj->text[4])) / result), 2));
	}
      else
	{
	  devia0 = devia;
	  devia = sqrt((((((pow(devia, 2) + pow(res, 2))) * (result - 1.0)) + pow(atof(obj->text[4]), 2)) / result) - pow((((res * (result - 1.0)) + atof(obj->text[4])) / result), 2));
	}
      sprintf(buf, "%.2f", devia);
      gtk_label_set(GTK_LABEL(obj->answer[1]), buf);

      /* aritmetique */
      if (i == 0)
	res = atof(obj->text[1]);
      res0 = res;
      res = ((res * (result - 1.0)) + atof(obj->text[4])) / result;
      sprintf(buf, "%.2f", res);
      gtk_label_set(GTK_LABEL(obj->answer[2]), buf);

      /* quadratique */
      if (i == 0)
	{
	  res1 = atof(obj->text[1]);
	  res1 = sqrt((((pow(atof(obj->text[3]), 2) + pow(res1, 2)) * (result - 1.0)) + pow(atof(obj->text[4]), 2)) / result);
	}
      else
	  res1 = sqrt((((pow(devia0, 2) + pow(res0, 2)) * (result - 1.0)) + pow(atof(obj->text[4]), 2)) / result);      sprintf (buf, "%.2f", res1);
      gtk_label_set(GTK_LABEL(obj->answer[3]), buf);

      /* harmonique*/
      if (i == 0)
	res2 = atof(obj->text[2]);
      if (atof(obj->text[0]) == 0 && atof(obj->text[2]) == 0)
	gtk_label_set(GTK_LABEL(obj->answer[4]), "Det harmoniske gennemsnit kan ikke beregnes");
      else {
	res2 = result / ((1.0 / res2 * (result - 1.0)) + (1.0 / atof(obj->text[4])));
	sprintf(buf, "%.2f", res2);
	gtk_label_set(GTK_LABEL(obj->answer[4]), buf);
      }
      i++;
  }
}

void		next_step_program(GtkWidget *button, gpointer data)
{
  t_obj		*obj;
  int		i;
  char		flag;

  obj = (t_obj *)data;
  flag = 0;
  for (i = 0; i < 4; i++) {
    obj->text[i] = strdup(gtk_entry_get_text(GTK_ENTRY(obj->entry[i])));
    if ((flag = check_argument(obj, (char *)obj->text[i])) == -1)
      break;
  }
  if (flag == 0) {
    gtk_label_set(GTK_LABEL(obj->error), "");
    for (i = 0; i < 4; i++)
      gtk_widget_destroy(obj->entry[i]);
    for (i = 0; i < 4; i++)
      gtk_widget_destroy(obj->label[i]);
    gtk_widget_destroy(obj->accept);
    for (i = 0; i < 4; i++)
      gtk_widget_destroy(obj->arg[i]);
    for (i = 0; i < 6; i++)
      obj->arg[i] = gtk_hbox_new(TRUE, 0);
    for (i = 0; i < 6; i++)
      gtk_box_pack_start(GTK_BOX(obj->box), obj->arg[i], TRUE, FALSE, 0);
    obj->label[0] = gtk_label_new("indtast din vaerdi :");
    obj->entry[0] = gtk_entry_new();
    obj->label[1] = gtk_label_new("antal mãlinder :");
    obj->label[2] = gtk_label_new("standardafvilgelse :");
    obj->label[3] = gtk_label_new("aritmetisk gennemsnit :");
    obj->label[4] = gtk_label_new("kvadratisk gennemsnit :");
    obj->label[5] = gtk_label_new("harmonisk gennemsnit :");
    for (i = 0; i < 5; i++)
      obj->answer[i] = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(obj->arg[0]), obj->label[0], TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(obj->arg[0]), obj->entry[0], TRUE, FALSE, 0);
    for (i = 1; i < 6; i++) {
      gtk_box_pack_start(GTK_BOX(obj->arg[i]), obj->label[i], TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(obj->arg[i]), obj->answer[i - 1], TRUE, FALSE, 0);
    }
    obj->accept = gtk_button_new_with_label("Godkend");
    gtk_box_pack_start(GTK_BOX(obj->box), obj->accept, TRUE, FALSE, 0);
    obj->error = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(obj->box), obj->error, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(obj->accept), "clicked", G_CALLBACK(calc), (t_obj *) obj);
    gtk_widget_show_all(obj->win);
  }
}

int		main(int ac, char **av, char **env)
{
  t_obj		*obj;
  int		i;

  if (env[0] == NULL)
    {
      std::cout << "Fejl: Miljøet blev slettet" << std::endl;
      return (-1);
    }
  i = 0;
  while (env[i] && (strstr(env[i], "DISPLAY") == 0))
    i++;
  if (env[i] == NULL)
    std::cout << "Display non présent" << std::endl;
  obj = (t_obj *)malloc(1);
  gtk_init(&ac, &av);
  obj->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(obj->win), "206neutrinos");
  gtk_window_set_default_size(GTK_WINDOW(obj->win), 300, 200);
  obj->box = gtk_vbox_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(obj->win), obj->box);
  for (i = 0; i < 4; i++)
    obj->arg[i] = gtk_hbox_new(TRUE, 0);
  obj->title = gtk_label_new("206neutrinos");
  obj->error = gtk_label_new("");
  obj->accept = gtk_button_new_with_label("Godkend");
  obj->label[0] = gtk_label_new("Antal indsamlede foranstaltninger :");
  obj->entry[0] = gtk_entry_new();
  obj->label[1] = gtk_label_new("Aritmetisk gennemsnit");
  obj->entry[1] = gtk_entry_new();
  obj->label[2] = gtk_label_new("Harmonisk gennemsnit");
  obj->entry[2] = gtk_entry_new();
  obj->label[3] = gtk_label_new("Standardafvigelse");
  obj->entry[3] = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(obj->box), obj->title, TRUE, FALSE, 0);
  for (i = 0; i < 4; i++)
    gtk_box_pack_start(GTK_BOX(obj->box), obj->arg[i], TRUE, FALSE, 0);
  for (i = 0; i < 4; i++) {
    gtk_box_pack_start(GTK_BOX(obj->arg[i]), obj->label[i], TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(obj->arg[i]), obj->entry[i], TRUE, FALSE, 0);
  }
  gtk_box_pack_start(GTK_BOX(obj->box), obj->accept, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(obj->box), obj->error, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(obj->win), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(obj->accept), "clicked", G_CALLBACK(next_step_program), (t_obj *) obj);
  gtk_widget_show_all(obj->win);
  gtk_main();
  return (0);
}
