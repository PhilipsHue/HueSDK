package com.philips.lighting.hue.demo.huequickstartapp;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.philips.lighting.hue.sdk.wrapper.discovery.BridgeDiscoveryResult;

import java.util.List;

class BridgeDiscoveryResultAdapter extends ArrayAdapter<BridgeDiscoveryResult> {
    BridgeDiscoveryResultAdapter(Context context, List<BridgeDiscoveryResult> results) {
        super(context, 0, results);
    }

    @Override
    @NonNull
    public View getView(int position, View convertView, @NonNull ViewGroup parent) {
        BridgeDiscoveryResult result = getItem(position);

        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.bridge_discovery_item, parent, false);
        }

        TextView bridge_id = convertView.findViewById(R.id.bridge_id);
        TextView bridge_ip = convertView.findViewById(R.id.bridge_ip);

        bridge_id.setText(result.getUniqueID());
        bridge_ip.setText(result.getIP());

        return convertView;
    }
}