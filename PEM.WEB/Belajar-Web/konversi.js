<SCRIPT language="JavaScript">
<!--
function konversi()
{
var MataUang = (document.form1.mata_uang.value);
var NilaiUang = parseFloat(document.form1.nilai_uang.value);
var NilaiKurs = parseFloat(document.form1.nilai_kurs.value);

if (MataUang = ="USD"){
    var hasil=NilaiUang*NilaiKurs;
    window.alert("Hasil Konversi adalah : " + hasil);
}
        else if (MataUang = ="IDR"){
    var hasil=NilaiUang/NilaiKurs;
    window.alert("Hasil Konversi adalah : " + hasil);
}
else {
window.alert("Mata uang yang anda masukan tidak valid");
}
}
//-->
</script>
