#!/bin/bash
(echo A)
(echo A && echo B)
((echo A && echo B) || echo C)
(((echo A || echo B) && echo C)
(((echo A && echo B) || echo C) && (echo D || echo E))
(((echo A && echo B) || echo C) && echo D)
