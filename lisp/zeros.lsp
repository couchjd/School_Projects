(defun zeros (list)
  (cond 
   ((not list)
    0)
   ((= 0 (car list))
    (+ 1 (zeros (cdr list))))
   ((/= 0 (car list))
    (+ 0 (zeros (cdr list))))
   )
  )

