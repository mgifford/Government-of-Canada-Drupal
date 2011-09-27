<?php

function govcan_nodes(){
  $body_txt_en = 
  ' <p>The Government of Canada Drupal Distribution is a pre-configured software platform that assists Governmental Departments in using a Content Management System that is already properly configured to Governmental functional and business requirements.</p>
    <h2>Brief Overview of Functionality Implemented</h2>
    <ul>
      <li>Custom Installation Profile GovCan</li>
      <li>Improved CLF Theme Integration in Drupal + Proper Inheritance with CLF_Custom</li>
      <li>Complex Access Control + Workflow (Workbench Module)</li>
      <li>Pre-Configured Roles + Users + Permissions</li>
      <li>Multilingualism</li>
      <li>WET Theme has been replaced into Module WETKIT</li>
      <li>WET Libraries Integration through custom WETKIT Module</li>
      <li>Installation + Configuration of best practice modules</li>
    </ul> 
  ';
  
  $body_txt_fr = 
  ' <p>Le gouvernement du Canada Drupal distribution est une plateforme de logiciel pré-configuré qui permet aux ministères gouvernementaux en utilisant un système de gestion de contenu qui est déjà correctement configuré pour gouvernementales exigences fonctionnelles et d\'affaires.</p>
    <h2>Bref aperçu des fonctionnalités implémentées</h2>
    <ul>
      <li>Profil personnalisé d\'installation GovCan</li>
      <li>Une meilleure intégration dans Drupal Theme NSI + héritage approprié aux CLF_Custom</li>
      <li>Contrôle d\'accès complexes + Workflow (module Workbench)</li>
      <li>Préconfigurés rôles + utilisateurs + autorisations</li>
      <li>Multilinguisme</li>
      <li>Thème WET a été remplacé dans le module Wetkit</li>
      <li>Intégration WET bibliothèques personnalisées grâce Wetkit module</li>
      <li>Installation Configuration + des modules de meilleures pratiques</li>
    </ul> 
  ';
  
  $translate_id = 1;
  add_translatable_node('article', $translate_id, 'Government of Canada Drupal Prototype', $body_txt_en, 'full_html', 'en');
  add_translatable_node('article', $translate_id, 'Gouvernement du Canada Drupal prototype', $body_txt_fr, 'full_html', 'fr');
}

function add_translatable_node($node_type, $translate_id, $node_title, $bodytext, $format_val, $language_type = LANGUAGE_NONE) {
  $node = new stdClass();
  $node->type = $node_type;
  node_object_prepare($node);
  
  $node->title    = $node_title;
  $node->language = $language_type;
  $node->uid      = $translate_id;
  $node->comment  = 0;
  $node->tnid     = $translate_id;
  $node->translate = 0;
  
  $node->body['und'][0]['value']   = $bodytext;
  //$node->body['und'][0]['summary'] = text_summary($bodytext);
  $node->body['und'][0]['format']  = $format_val;
  $node->status = 1;
  
  if($node = node_submit($node)) {
    node_save($node);
  }
}
