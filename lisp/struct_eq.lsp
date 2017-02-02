(defun struct_eq (list1 list2)
  (cond
   ((and (not list1) (not list2)) ;both lists are empty
    '(EQUIVALENT))
   ((or (not list1) (not list2)) ;one list is empty
    '(NOT EQUIVALENT))
   ((and (not (listp (car list1))) (not (listp (car list2)))) ;if both cars are atoms 
    (struct_eq (cdr list1) (cdr list2)))
   ((or (and (listp (car list1)) (not (listp (car list2)))) ;if one car is an atom and the other
	(and (listp (car list2)) (not (listp (car list1)))));is not
    '(NOT EQUIVALENT))
   (t
    (and (struct_eq (car list1) (car list2))
	 (struct_eq (cdr list1) (cdr list2))))
 )  
)
