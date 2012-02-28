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
<html lang="<?=config::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $_SERVER['SERVER_NAME'] . MENU_SUB_SEPARATOR_SEC .  template::getTitle(); ?></title>


<link rel="stylesheet" type="text/css" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.17/themes/hot-sneaks/jquery-ui.css" />

    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.17/jquery-ui.min.js"></script><link href="/templates/mandlen/grid.css" type="text/css" rel="stylesheet" media="screen"/>
<script src="/js/jquery.tr.js"></script>
<?php

echo template::getMeta();

template::setTemplateCss('mandlen', 10, 13);

echo template::getCss();
echo template::getInlineCss();

// print_r(template::$css);


?>


</head>
<body>

    <div id ="hidden">
<a href="/account/login/index">logon</a>
</div>

<div id ="page">
    
    <?php

if (session::isAdmin()) { ?>
    <div class="row">
            <div class="column grid_12">
                <div id="system_admin_menu">
            <?php
$blocks = layout::getBlock('blocks_top');
                foreach ($blocks as $key => $val){
                    echo $val;
                }

?>

                 </div>
                        
           </div>

    </div>
<?php } ?>

    <div class="row">
            <div class="column grid_3">
            &nbsp;
            </div>
            <div class="column grid_9">


                <?=template::getLogoHTML(); ?>



            </div>

    </div>

    <div class="row">
            <div class="column grid_3">
            &nbsp;
            </div>
            <div class="column grid_9">
                <div id="main_menu">
                <?php
                    echo layout::getMainMenu(); ?>
                </div>
            </div>
    </div>

    <div class="row">
        <div class="column grid_3">
                <div id="sidebar_left">
                <?php

                $blocks = layout::getBlock('blocks');
                foreach ($blocks as $key => $val){
                    print $val;
                }

                ?>
                </div>
         </div>

         <div class="column grid_6">
             <div id="module_menu"><?php
               echo layout::getModuleMenu(); ?>
             </div>

             <div class="system_message">
            <?php

            echo session::getActionMessage();

            ?>
            </div>
             <div id="content">


<?php

// end of function

}

/**
 * method for print footer of page
 */
public static function printFooter(){ ?>


             </div>
        </div>
        <div class="column grid_3">
            <div id="sidebar_right">
                <?php

                $blocks_sec = layout::getBlock('blocks_sec');
                foreach ($blocks_sec as $key => $val){
                    print $val;
                }

                ?>
            </div>
         </div>
    </div>


    <div class="row">
            <div class="column grid_12">
            <?=template::getEndContent()?>
            </div>
    </div>
    
</div>
    
    <?php

echo template::getInlineJs();
echo template::getJs();

?>
</body>
</html>

<? 

    // end function

    }
    
// end class
}

