(defun frac (n)
  (if (> n 0)
      (/ 1
         (+ 2 (frac (1- n))))
      0)
  )

(defun numdigits (n)
  (cond
    ((< n 10) 1)
    (t (1+ (numdigits (truncate n 10))))
    )
  )

(defun numhasmoredigits (n)
  (setf *frc* (1+ (frac n)))
  (if (> (numdigits
          (numerator *frc*))
         (numdigits
          (denominator *frc*))
         )
      1
      0)
  )

(defvar *ctr* 0)
(defun countones (list)
  (if list
      (progn (if (= (car list) 1)
                 (setf *ctr* (1+ *ctr*))
                 )
             (countones (cdr list)))
      (progn (print *ctr*)
             (setf *ctr* 0)
             )             
      )
  )
  

(countones (loop for n from 1 to 1000
              collect (numhasmoredigits n)))
