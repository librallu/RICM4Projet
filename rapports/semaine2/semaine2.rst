Test de micropython sur STM32
-----------------------------

Après avoir suivi la méthode d'installation décrite ici (https://github.com/micropython/micropython).
La carte STM32 fonctionnait avec micropython et un shell interactif était disponible
sur nos machines pour lancer des commandes python sur la carte.


Installation du toolchain
-------------------------

Installer le toolchain pour utiliser la carte :

 - récupérer les sources ici (*git clone https://github.com/pfalcon/esp-open-sdk*).
 - cd *esp-open-sdk*.
 - *make STANDALONE=y* ou *make STANDALONE=n* (temps estimé 30 à 40 min). 
   Il y a deux options car certains composants
   du sdk ne sont pas libres, en indiquant l'option *y* tout sera intégré en un tout
   ce qui sera simple pour compiler des programmes mais rend les mises à jour de ceux-ci
   plus difficile. 
 - ajouter *export PATH=[chemin vers le sdk]/esp-open-sdk/xtensa-lx106-elf/bin:$PATH*
   dans le **.bashrc** ou l'entrer dans le terminal
 - les commandes *xtensa-lx106-elf-gcc*, *xtensa-lx106-elf-g++*, ...
   sont maintenant disponibles.


 
Plus d'informations ici : https://github.com/pfalcon/esp-open-sdk


Nodemcu
-------

Nous avons également jetté un oeil à **nodemcu** qui permet de programmer
l'ESP8266 en *Lua* : https://github.com/nodemcu/nodemcu-firmware.

Cela permettrait d'avoir une manière simple de réaliser des programmes 
tout en ayant des exécutables petits. Ce qui peut être intéressant.

Pour l'installer, il est nécessaire d'avoir installé xtensa avant (voir section
ci-dessus)



**procédure d'installation :**

 - Commençons par récupérer le firmware ici : *git clone https://github.com/nodemcu/nodemcu-firmware*
 - Nous pouvons maintenant le compiler en se déplaçant dans le répertoire en question et en entrant la 
   commande *make*




**Problèmes résolus : **

Lors d'une première compilation sur *archlinux*, nous avons obtenu le
message d'erreur suivant pendant l'exécution de la commande *make* :

	  File "../tools/esptool.py", line 131
		print 'Connecting...'
							^
Cela vient du fait que dans le fichier *tools/esptool.py*, la
première ligne : *#!/usr/bin/env python* fait référence à l'interpréteur
python ayant la version 3.4. Or dans cette version, l'instruction *print*
devient une fonction comme une autre et il est nécessaire 


Ressources Utiles
-----------------

- http://gpio.kaltpost.de/?p=2082
