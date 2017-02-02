(load "power.lsp")
(load "zeros.lsp")
(load "struct_eq.lsp")

(defun testing ()
  (print '(power 2 6))
  (print (power 2 6))

  (print '(power 9 2))
  (print (power 9 2))

  (print '(zeros '(0 0 0 0 0 0 0)))
  (print (zeros '(0 0 0 0 0 0 0)))

  (print '(zeros '(1 2 3 4 5 6 7)))
  (print (zeros '(1 2 3 4 5 6 7)))

  (print '(zeros '(0 1 2 3 4 5 0)))
  (print (zeros '(0 1 2 3 4 5 0)))

  (print '(struct_eq '(0 1 2 3) '(4 5 6 7)))
  (print (struct_eq '(0 1 2 3) '(4 5 6 7)))

  (print '(struct_eq '(0 (1 2) 3) '(4 (5 6) 7)))
  (print (struct_eq '(0 (1 2) 3) '(4 (5 6) 7)))

  (print '(struct_eq '(0 (1 2) 3) '(4 5 6 7)))
  (print (struct_eq '(0 (1 2) 3) '(4 5 6 7)))

  (print '(struct_eq '(0 1 2 3) '(4 (5 6) 7)))
  (print (struct_eq '(0 1 2 3) '(4 (5 6) 7)))

  (print '(struct_eq '() '()))
  (struct_eq '() '())
)
