;; Highlight modus for GetPot input parameter files
;;-------------------------------------------------------------
;;
;;    This library is free software; you can redistribute it and/or
;;    modify it under the terms of the GNU Lesser General Public
;;    License as published by the Free Software Foundation; either
;;    version 2.1 of the License, or (at your option) any later version.
;;
;;    This library is distributed in the hope that it will be useful,
;;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;;    Lesser General Public License for more details.
;;
;;    You should have received a copy of the GNU Lesser General Public
;;    License along with this library; if not, write to the Free Software
;;    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
;;
;; Append the content of this file to your ./emacs file in your
;; home directory, i.e. type 
;;
;;    shell> cat emacs-getpot-mode.el >> $HOME/.emacs
;;  
;; it enables a so called 'getpot-mode' with nice
;; colors for getpot input files ...
;;
;; Caution: you might insert a label '-*- getpot -*-' in your getpot
;; files with extension '.pot', since otherwise emacs does strange
;; things with it :-/.
;;
;; enjoy,
;;
;; August 2001,
;; Frank R. Schaefer
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defface getpot-mode-section-face
     '((((class color)) (:foreground "Wheat" :bold t :background "DarkOliveGreen"))
       (t               (:underline t)))
     "Grey flags to indicate section labels.")
(defface getpot-mode-variable-name-face
     '((((class color)) (:foreground "DarkGoldenrod" :bold t))
       (t               (:underline t)))
     "Grey flags to indicate section labels.")

(define-generic-mode 'getpot-mode
                     (list ?# )
                     (list "GetPot" "getpot")
		     '(("\\(\\[.*\\]\\)" 1 'getpot-mode-section-face)
		       ("\\(.*\\)="      1 'getpot-mode-variable-name-face))
		     (list "\.pot")
		     (list 'getpot-mode-setup))
(defun getpot-mode-setup() nil)
(global-font-lock-mode t)




