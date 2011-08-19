<?php

include "layout2.php";

class mainTemplate extends template {

/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!doctype html>
<html lang="<?=register::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<title><?php echo $_SERVER['HTTP_HOST']?> :: <?php echo template::getTitle(); ?></title>
<link rel="stylesheet" type="text/css" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/themes/hot-sneaks/jquery-ui.css" />
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.0/jquery.min.js"></script>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/jquery-ui.js"></script>


<?php

echo template::getMeta();

template::setCss('/templates/mandlen/grid.css');
template::setCss('/templates/mandlen/common.css?version=17');

echo template::getCss();
echo template::getInlineCss();

echo template::getJs();
echo template::getInlineJs();
?>

</head>
<body>
<div id ="hidden">
<a href="/account/login/index">logon</a>
</div>
<div id="page">

    <div id="header">
        <?php if (empty(register::$vars['coscms_main']['logo'])) { ?>
            <div id ="logo_title"><a href="/"><?php echo $_SERVER['HTTP_HOST']?></a></div><?php
        } else { ?>
            <div id = "logo_img"><a href="/"><img alt="<?php echo $_SERVER['HTTP_HOST']?>" src="/logo/<?=register::$vars['coscms_main']['logo']?>" /></a></div><?php
        } ?>
        <div id="main_menu"><?php
echo layout2::getMainMenu();

?>

    </div>
        <div id ="top_blocks">
<?php

$blocks = layout2::getTopBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
        </div>
    </div>
    
    <div id="sidebar_left">
        <div id ="block_menu">
<?php

$blocks = layout2::getBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
        </div>
    </div>
    
    
    <div id="content">
        <div id="module_menu">
<?php

echo layout2::getModuleMenu();

?>
        </div>
        <div id="system_message"><p>
<?php

echo session::getActionMessage();

?>
        </p></div>

<?php

// content of loaded module will be printed

}

/**
 * method for print footer of page
 */
public static function printFooter(){

?>
    <div id="sidebar_right">
        <div id ="block_menu_right">
<?php

$blocks_sec = layout2::getBlocksSec();
foreach ($blocks_sec as $key => $val){
      print $val;
}


?>
        </div>
   </div>


            <div id="end_content">
<?php

echo template::getEndContent();

?>
        </div>
    </div>
    <div id="footer">
    <?=register::$vars['coscms_main']['footer_message']?>
    </div>
</div>
<?php

echo template::getEndHTML();

?>
</body>
</html>
<?php

}
    
// end of class 
}
