# Jsontrans
<hr\>
Обработка JSONperline файла.
На выходе формируется фаил с такой же структурой с постфиксом *_out*

*Каждая строка файла содержит следующие поля*
|Имя поля|Содержимое                 |Обработка                                                                     |
|--------|---------------------------|------------------------------------------------------------------------------|
|iValue  |Целое число                |Если число меньше 5, то записывается 0. Если в интервале [5;50) - 5, иначе 50.|
|dtValue |Дата в формате "31.12.2020"|Записывается год                                                              |
|sValue1 |Строка                     |Формируется MD5-hash                                                          |
|sValue2 |Строка                     |Добавляется префикс к строке                                                  |
|sValue3 |Строка                     |Строка переводится в большие буквы                                            |

**Пример**

*Входной фаил JSONperline*
```
{"iValue": 60, "dtValue": "15.04.2003", "sValue1": "ojxmn,tjev?tyTB?KyNxhSVEQoYPuByYP.nEFUXIQf,ESHfZ?B: Xwyvr.SnaU", "sValue2": "VaLxXBD zVkWNIr:UE GjnchCjkDFCLokWCwIkr?Rtye,GKJKPcvPTaryXuAZenH", "sValue3": "ITXghAdLMMhc KKelBjcGlNoDNvrJ"}
{"iValue": 28, "dtValue": "20.07.2020", "sValue1": "jxAcSQOKlrxbjx,q:VPe:QycGxIzQggvpxNgtm OyOEgxBgTttVdowULNOWjWnwDlGOzJoymGqyuWDo", "sValue2": "UI.BE,VFAwZbVspAYsI:fNnlzzlJTMnqASTIgtdwTctzEQOVqcCwpSGFZBBllkE", "sValue3": "f?GG.XnC.Vcj.lygaeLDJpJTaUR.vHXgqvayQartpmaMoutMJRaTdvQIYVnfVmPtbZrXcVurQAkBGAj,"}
```

*Выходной фаил JSONperline*
```
{"iValue":"50","dtValue":"2003","sValue1":"1689D2FD738C0099D5632B33AF6A39A2","sValue2":"PREFIX_VaLxXBD zVkWNIr:UE GjnchCjkDFCLokWCwIkr?Rtye,GKJKPcvPTaryXuAZenH","sValue3":"ITXGHADLMMHC KKELBJCGLNODNVRJ"}
{"iValue":"5","dtValue":"2020","sValue1":"5769D097866568849F2E6960118B2E81","sValue2":"PREFIX_UI.BE,VFAwZbVspAYsI:fNnlzzlJTMnqASTIgtdwTctzEQOVqcCwpSGFZBBllkE","sValue3":"F?GG.XNC.VCJ.LYGAELDJPJTAUR.VHXGQVAYQARTPMAMOUTMJRATDVQIYVNFVMPTBZRXCVURQAKBGAJ,"}
```

## Запуск
`jsontrans.exe js.json`

## Сборка
Сборка осуществляется с использовнием CMake 3.20.

Для сборки необходим Boost 1.75.