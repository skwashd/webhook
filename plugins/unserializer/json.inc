<?php

/**
 * @file
 *   JSON unserializer plugin.
 */

$plugin = array(
  'title' => t('JSON'),
  'handler' => array(
    'class' => 'Webhook_Plugins_Unserializer_Json',
  ),
);

/**
 * Webhook unserializer plugin for JSON.
 */
class Webhook_Plugins_Unserializer_Json implements Webhook_Plugins_Unserializer_Interface {
  public function unserialize($data) {
    $unserialized = json_decode($data);
    if (is_null($unserialized) && trim($data) != '') {
      throw new Webhook_Plugins_Unserializer_InvalidDataException(t('Unable to unserialize data'));
    }

    return $unserialized;
  }
}
