  

(invert-face 'default)

;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(package-initialize)

(add-to-list 'load-path "~/emacs-load-path")

(autoload 'csharp-mode "csharp-mode" "Major mode for editing C# code." t)
;;   (setq auto-mode-alist
;;      (append '(("\\.cs$" . csharp-mode)) auto-mode-alist))

(when (file-directory-p "~/emacs-load-path")
  (load "~/emacs-load-path/php-mode-autoloads.el"))

(set-face-foreground 'font-lock-comment-face "#009900")
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(cua-mode t nil (cua-base))
 '(global-display-line-numbers-mode t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Consolas" :foundry "outline" :slant normal :weight normal :height 143 :width normal)))))

(setq c-default-style
      '((java-mode . "java")
        (awk-mode . "awk")
	(c++-mode . "k&r")
        (c-mode . "k&r")))
        
(defun sort-lines-nocase ()
	  (interactive)
	  (let ((sort-fold-case t))
	    (call-interactively 'sort-lines)))

(setq frame-title-format
      (list (format "%s %%S: %%j " (system-name))
            '(buffer-file-name "%f" (dired-directory dired-directory "%b")

			       )))

(global-set-key [f12] 'amanda_e_ricardo_function_27_51)

(defun amanda_e_ricardo_function_27_51 ()
  (interactive)
  (set-background-color '"#000020")
  (set-foreground-color '"#ccccff")
  (set-face-foreground 'font-lock-comment-face "#88ff00")
 )

(global-set-key [f11] 'amanda_e_ricardo_function_27_51_v2)

(defun amanda_e_ricardo_function_27_51_v2 ()
  (interactive)
  (set-background-color '"#000000")
 )

(global-set-key [f4] 'amanda_e_ricardo_function_27_51_v3)

(defun amanda_e_ricardo_function_27_51_v3 ()
  (interactive)
  (set-face-foreground 'font-lock-comment-face "#3cee3c")
 )

(global-set-key [f5] 'amanda_e_ricardo_function_27_51_v4)

(defun amanda_e_ricardo_function_27_51_v4 ()
  (interactive)
  (set-face-foreground 'font-lock-comment-face "#4bff4b")
 )

(global-set-key [f2] 'amanda_e_ricardo_function_27_51_v5)

(defun amanda_e_ricardo_function_27_51_v5 ()
  (interactive)
   (set-foreground-color '"#ebebe0")
 )

(global-set-key [f3] 'amanda_e_ricardo_function_27_51_v6)

(defun amanda_e_ricardo_function_27_51_v6 ()
  (interactive)
   (set-foreground-color '"#ffcccc")
 )
