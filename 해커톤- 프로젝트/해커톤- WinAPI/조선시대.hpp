
void �����ô�(EventManager& evt_mng)
{
	{
		EventMaker e("��ȭ��ȸ��", EventPriority::Normal);

		e->content =
			"��հ� �ֿ��� �䵿 �����̶�� ������ �䱸�� �ϰ� �ֽ��ϴ�.\n\
�̼���� ��Ұ����� ��� �ݴ��Ͽ����� �ᱹ ����� �����Ͽ����ϴ�.\n\
��ȭ���� �����Ͽ����ϴ�.���� ��â �帶ö�̹Ƿ� Ȱ�� �Ʊ��� Ǯ������, ���� ������� ������ ���� ���Դϴ�";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["��ȭ��ȸ��"] == "" && data.dict["���ź��"] == "�����Ǳ�")
			{
				data.dict["��ȭ��ȸ��"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���븦 �������� ������!");
			s->content =
				"���븦 ���� �������� ���� ��Ÿ�� ����ŵ�ϴ�.\n\
�ķ�-";

			s->Effect = [&](Gamedata& data) {
				data.dict["��ȭ��ȸ��"] = "����";
			};
		}

		{
			EventSelectItemMaker s(e, "�䵿�� �����Ϸ� ����!");
			s->content =
				"�䵿�� �����Ϸ� ���ϴ�\n\
�����--";
			s->Effect = [&](Gamedata& data) {
				data.dict["��ȭ��ȸ��"] = "����";
				data.player.res.milli -= 10000;
			};
		}
	}

	//��ȭ�� ȸ��
	{
		EventMaker e("��ȭ��ȸ��", EventPriority::Normal);

		e->content =
			"���濡 �����Ͽ����ϴ�. ���� ������ ������ ����� �����Դϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["��ȭ��ȸ��"] == "����")
			{
				data.dict["��ȭ��ȸ��"] = "����";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "����� ���̰� ��Ÿ�� ����Ų��.");
			s->content = "��Ÿ�� ����ŵ�ϴ�. �̼���� ������ ������ �Ǳ��ϰ� �˴ϴ�.\n\
�ڱ�-\n\
�η�-\n\
�ž�+\n\
�����+";


			s->Effect = [&](Gamedata& data) {
				data.dict["��ȭ��ȸ��"] = "����";
				data.dict["�÷��̾�"] = "����";
				data.dict["�ô�"] = "�����ô�";
				data.player.res.money -= 1;
				data.player.res.milli += 2;
				data.player.res.human -= 1;
				data.player.res.faith += 1;
			};
		}

		{
			EventSelectItemMaker s(e, "������ ĥ �� �����ٰ� ��տ��� ���Ѵ�.");
			s->content = "����� ũ�� ���ϸ� �̼����� ������ ��Ż�մϴ�.\n\
�ž�-";


			s->Effect = [&](Gamedata& data) {
				data.dict["��ȭ��ȸ��"] = "����";
				data.player.res.faith -= 10000;
			};
		}
	}

	{
		EventMaker e("�ƹ�����â��", EventPriority::Normal);
		e->content =
			"�Ϸ����� �԰��� ���� ���� �ϴ� �鼺���� ���ڸ� ���⿣ ���������,\n\
���ο� ���ڸ� �����ڴ� �������� �ݹ��� �ʹ� �ż�����";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�����ô�") return false;
			if (data.dict["�ƹ�����â��"] == "")
			{
				data.dict["�ƹ�����â��"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ���ڸ� ��� ���!");
			s->content =
				"�鼺���� ��� ���ڸ� �𸣰� ��Եǰ�,\n\
�ʳ����� �츮����� �������� ���մϴ�\n\
�ž�-";

			s->Effect = [&](Gamedata& data) {
				data.player.res.faith -= 10000;
			};
		}

		{
			EventSelectItemMaker s(e, "�ƹ������� ����°Ŵ�!");
			s->content =
				"�ƹ������� â���� �����մϴ�\n\
�ڱ�-�ž�+�η�+";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ƹ�����â��"] = "â��";
				data.player.res.money -= 2;
				data.player.res.money += 1;
				data.player.res.faith += 2;
			};
		}
	}

	//�ƹ����� â��
	{
		EventMaker e("�ƹ�����â��", EventPriority::Normal);

		e->content =
			"���(����)�� ���ǰ��� ������ �� �̻� �ƹ������� â���ϱ� ����ϴ�\n\
�ٸ� ������� �ñ⼼��";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�����ô�") return false;
			if (data.dict["�ƹ�����â��"] == "â��")
			{
				data.dict["�ƹ�����â��"] = "����";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ���ڵ����� �ñ��.");
			s->content = "������ ���ڵ��� ������ ���ϴ� �ٸ�\n\
�̷ﳾ���� �ǹ��Դϴ�. ������ �Ƿ��� �ſ� �پ ���ڵ�����.\n\
�ڱ�-\n\
�η�-\n\
�ž�+";


			s->Effect = [&](Gamedata& data) {
				data.dict["�ƹ�����â��"] = "����";
				data.player.res.money -= 1;
				data.player.res.human -= 1;
				data.player.res.faith += 1;
			};
		}

		{
			EventSelectItemMaker s(e, "���� ���� ����ڴ�");
			s->content = "���� ��Ȯ�ϰ� ����� �ְ�����,������ �ǰ��� ��ȭ�� �� �ֽ��ϴ�.\n\
�ž�-";


			s->Effect = [&](Gamedata& data) {
				data.dict["�ƹ�����â��"] = "����";
				data.player.res.faith -= 10000;
			};
		}
	}
	{
		EventMaker e("ȯ��", EventPriority::Low);
		e->content =
			"������ �ñȿ��� ȯ���� �Ͼ���ϴ�. �����ο��� ���ο� ������ ���Ǿ����ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return evt_mng.RandomInt(0, 4) == 0;
		};


		{
			EventSelectItemMaker s(e, "�׳��� �׳��̴�.");
			s->content =
				"�ܱ���+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo += 2;
			};
		}
	}
	{
		EventMaker e("��ȭ", EventPriority::Low);
		e->content =
			"������ �ñȿ��� ��ȭ�� �Ͼ���ϴ�. �� �������� ���� ����Դϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return evt_mng.RandomInt(0, 6) == 0;
		};


		{
			EventSelectItemMaker s(e, "����");
			s->content =
				"�ܱ���-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo -= 2;
			};
		}
	}


	//������ �ӻ���
	{
		EventMaker e("������ �ӻ���", EventPriority::Highest);

		e->content =
			"�ֱ� �ֱ��� �ϳ��� ����� ���ϵž���\n\
�� �������� �ֱ��� ħ���� �������̰� ��ȭ�Ͽ����ϴ�.\n\
�׿� ���� �츮�� ������ �ֱ��� ���������� �ڸ��� \n\
�� �߰� ���Ѻ� �� �ۿ� �����ϴ�.\n\
�츮�� �̸� �������� ��å�� ������ �մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�����ֶ�"] == "" && evt_mng.RandomInt(0, 6) == 0)
			{
				data.dict["�����ֶ�"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���� ������� �����϶�!");
			s->content =
				"��������� �����մϴ�.\n\
�ڱ�-";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "�������";
			};
		}
		{
			EventSelectItemMaker s(e, "�ؾȰ��� ����� ���� �� �ϵ��� �ض�!(�رݷ�)");
			s->content =
				"�رݷ��� ����մϴ�.\n\
�ڱ�-\n\
�ķ�-";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.dict["�رݷ�"] = "��";
			};
		}
		{
			EventSelectItemMaker s(e, "��ư �Ҹ� ����!");
			s->content =
				"�ƹ� ��� ���� �ʽ��ϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
			};
		}
	}

	//�������
	{
		EventMaker e("������ ���� �����", EventPriority::Normal);

		e->content =
			"����������� �ֱ��� ���� ��å�� ����� ���� �Ѿ翡 �𿴽��ϴ�\n\
���� �ڽ��� �ǰ��� �����ϰ� �ֽ��ϴ�. �׷��� ���� ���ָ� ���� �Ǵ��� �ϴ°� ����Դϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�����ֶ�"] == "�������")
			{
				data.dict["�����ֶ�"] = "���ﵹ��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ������ �����ϰ� �Ѵ�.");
			s->content =
				"�״� ��ҿ� ������ ���� ������ ���ĿԽ��ϴ�.\n\
���� �������� �������մϴ�. �׷��� ���� �������� �׷��� ���� ���� �ֽ��ϴ�.\n\
�ڱ�+\n\
����-\n\
�η�-";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.player.res.money += 7;
				data.player.res.milli -= 3;
				data.player.res.human -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "�̼����� ������ �����ϰ� �Ѵ�.");
			s->content =
				"�״� �Ƿӱ�� �ҹ��� ����Դϴ�. �׷��� ���� �Ƿ��� ������� �ʾҽ��ϴ�.\n\
�ڱ�-\n\
����+\n\
�η�+";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.player.res.money -= 1;
				data.player.res.milli += 8;
				data.player.res.human += 7;
			};
		}
		{
			EventSelectItemMaker s(e, "�����ڰ� ���⿡ ���°� ����!");
			s->content =
				"�� �������Ե� �ñ� ���� ����. ���� ���� �����ϰڴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
			};
		}
	}

	//���ﵹ��
	{
		EventMaker e("���ﵹ��", EventPriority::Normal);

		e->content =
			"�ֱ��� �������� ����ߴٰ� ������ �Խ��ϴ�. �ֱ��� �������� ���� ���� ���� ġ���� �ϴ� \n\
�游 �����ָ�. �ƹ� ���ص� ������ �ʰڴٰ� ����߽��ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "���ﵹ��";
		};

		{
			EventSelectItemMaker s(e, "�׵��� ���ƶ�! ���� �� ������ ���°� �и��ϴ�!");
			s->content =
				"���� �ĺ��մϴ�.\n\
����-\n\
�η�-\n\
�ķ�-\n\
��-";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "�ֿ� ����";
				data.player.res.milli -= 5;
				data.player.res.human -= 4;
				data.player.res.food -= 3;
				data.player.res.money -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "���� �����ִ� ������ �� ������� ������?\n\
���ص� �� �����ڴٰ� ������� �ʾҴ°�?");
			s->content = "�ֱ����� ���� ���� �ݴϴ�.\n\
�й��մϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "��";
				data.player.res.milli = -1;
				data.player.res.faith = 0;
			};
		}
		{
			EventSelectItemMaker s(e, "�߱����� �� ���� ��Ű�ڴ�! ������� ���� �˾Ƽ� �غ��ƶ�!");
			s->content =
				"�߱����� �����մϴ�.\n\
";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���� ����";
			};
		}
	}
	{
		EventMaker e("������ �뱺", EventPriority::Low);
		e->content =
			"������ ���밡 Ȳ�ظ� �ǳ� �� �ѹݵ��� ����մϴ�.\n �׵��� ���ָ� �츮�� �鼺�� ���� ������ ���� �մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "���� ����";
		};


		{
			EventSelectItemMaker s(e, "�׵鿡�� ���� ������ �־��");
			s->content =
				"�η�++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human += 6;
				data.dict["�����ֶ�"] = "�ֿ� ����";
			};
		}
	}
	{
		EventMaker e("�ֿ� ����", EventPriority::Low);
		e->content = "�ֱ��� �ѹݵ��� ���ƴٴϸ� ���������� �ֽ��ϴ�. � �׵��� ��ġ�����մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "�ֿ� ����";
		};


		{
			EventSelectItemMaker s(e, "�ο���");
			s->content = "������ ���� �η°� ������� �Ҹ�˴ϴ�.\n";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= evt_mng.RandomInt(0, 3);
				data.player.res.milli -= evt_mng.RandomInt(0, 3);
				if (evt_mng.RandomInt(0, 5)) data.dict["�����ֶ�"] = "�¸�";
			};
		}
		{
			EventSelectItemMaker s(e, "�׺�.");
			s->content =
				"�й��մϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "��";
				data.player.res.milli = -1;
				data.player.res.faith = 0;
			};
		}
	}
	{
		EventMaker e("�����ֶ��� ��", EventPriority::Low);
		e->content = "�ֱ��� �ٽ� �׵��� ������ ���ư����ϴ�. �츮�� �� ���� ����ϰ� �ٽô� �̷����� �Ͼ�� �ʵ��� �ؾ��մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "�¸�";
		};

		{
			EventSelectItemMaker s(e, "����.");
			s->content = "�����+\n�ž�++\n�ķ�-\n�η�-";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "��";
				data.dict["�ٴ��"] = "����ȣ��";
				data.player.res.milli += 3;
				data.player.res.faith += 12;
				data.player.res.food -= 3;
				data.player.res.human -= 3;
			};
		}
	}
	{
		EventMaker e("����ȣ��", EventPriority::Low);
		e->content = "�������� �������� ������ �߸����̿����ϴ�. �׷��� �׵��� �����θ� û�̶� �θ��� �츮���� ������ �����߽��ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "�¸�";
		};

		{
			EventSelectItemMaker s(e, "��¿�� ����.");
			s->content = "(��˱���ηʸ� �մϴ�)\n�ܱ���-\n�ž�+";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ٴ��"] = "���丣Ʈ";
				data.player.res.diplo -= 3;
				data.player.res.faith += 3;
			};
		}
	}
	{
		EventMaker e("���丣Ʈ ���� ���", EventPriority::Low);
		e->content = "�������� ���� ���� �Ǿ����ϴ�. .";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�����ֶ�"] == "���丣Ʈ")
			{
				if (data.dict["�رݷ�"] == "��")
				{
					data.dict["�ٴ��"] = "�����չ�";
					return false;
				}
				return true;
			}
			else
			{
				return false;
			}
			
		};

		{
			EventSelectItemMaker s(e, "������ ������!");
			s->content = "�ܱ���-\n�ž�+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo -= 3;
				data.player.res.faith += 3;
				data.dict["�ٴ��"] = "�����չ�";
			};
		}
	}
	{
		EventMaker e("�������", EventPriority::Low);
		e->content = "�Ϻ��� �츮������ �ܱ����� ��Ż�ϴ� ������ ����ü���߽��ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�رݷ�"] == "�����չ�")
			{
				return false;
			}
			return false;
		};

		{
			EventSelectItemMaker s(e, "����!");
			s->content = "1949������ Ÿ�ӿ��� �մϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ô�"] = "�ٴ�ô�";
				data.dict["�÷��̾�"] = "���ѹα�";
			};
		}
	}
}
